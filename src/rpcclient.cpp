#include <string.h>
#include <iostream>

#include <chord/rpcclient.hpp>
#include <chord/transport.hpp>

#include "../chord.pb-c.h"


//=====================================================================================
// Pack Arguments and Send Call
//=====================================================================================

static int make_call(size_t argsSerialLen, uint8_t *argsSerial, Protocol__Return **ret, const char *name, int sockfd)
{
    int error= 0;

    // Pack and send the call 
    Protocol__Call call= PROTOCOL__CALL__INIT;
    call.name= (char *)name;
    call.args.len= argsSerialLen;
    call.args.data= argsSerial;

    size_t callSerialLen= protocol__call__get_packed_size(&call);
    uint8_t *callSerial= (uint8_t *)malloc(callSerialLen);
    if (callSerial == NULL) 
        return 1;

    protocol__call__pack(&call, callSerial);
    Transport::send_RPC(sockfd, callSerialLen, callSerial);

    // Recv and unpack the return value
    uint8_t *retSerial;
    size_t retSerialLen;

    retSerial= Transport::recv_RPC(sockfd, &retSerialLen);
    *ret = protocol__return__unpack(NULL, retSerialLen, retSerial);
    if (*ret == NULL)
        error = 1;

    return error;
}


//=====================================================================================
// Outgoing RPC Calls to Remote Nodes
//=====================================================================================

Node RPCClient::find_successor(Node n, uint8_t *key)
{
    Node succ;

    int sockfd= Transport::get_conn(n.ip.c_str(), n.port);
    if (sockfd == -1)
    {
        std::cout << "get_conn() error" << std::endl;
        return succ;
    }
    
    
    // Serialize the call and send to remote node
    Protocol__FindSuccessorArgs args= PROTOCOL__FIND_SUCCESSOR_ARGS__INIT;
    args.id.len= ID_LEN;
    args.id.data= key;
    
    size_t argsSerialLen = protocol__find_successor_args__get_packed_size(&args);
    uint8_t *argsSerial = (uint8_t *)malloc(argsSerialLen);

    protocol__find_successor_args__pack(&args, argsSerial);

    int err= 0;
    Protocol__Return *ret= NULL;
    err= make_call(argsSerialLen, argsSerial, &ret, "findsuccessor", sockfd);
    if (err)
    {
        std::cout << "make_call() error" << std::endl;
        return succ;
    }
    
    Transport::close_conn(sockfd);
    
    // Return the value received 
    Protocol__FindSuccessorRet *value = protocol__find_successor_ret__unpack(NULL, ret->value.len, ret->value.data);

    if (ret->success) 
    {
        memcpy(succ.id, value->node->id.data, ID_LEN);
        succ.ip= value->node->address;
        succ.port= value->node->port;
    }

    return succ;    
}

Node RPCClient::get_predecessor(Node succ)
{
    Node pred;

    int sockfd= Transport::get_conn(succ.ip.c_str(), succ.port);
    if (sockfd == -1)
    {
        std::cout << "get_conn() error" << std::endl;
        return pred;
    }
    
    // Serialize the call and send to remote node
    Protocol__GetPredecessorArgs args= PROTOCOL__GET_PREDECESSOR_ARGS__INIT;
    
    size_t argsSerialLen = protocol__get_predecessor_args__get_packed_size(&args);
    uint8_t *argsSerial = (uint8_t *)malloc(argsSerialLen);

    protocol__get_predecessor_args__pack(&args, argsSerial);

    int err= 0;
    Protocol__Return *ret= NULL;
    err= make_call(argsSerialLen, argsSerial, &ret, "getpredecessor", sockfd);
    if (err)
    {
        std::cout << "make_call() error" << std::endl;
        return pred;
    }
    

    Transport::close_conn(sockfd);
    
    // Return the value received 
    Protocol__GetPredecessorRet *value = protocol__get_predecessor_ret__unpack(NULL, ret->value.len, ret->value.data);

    if (ret->success) 
    {
        memcpy(pred.id, value->node->id.data, ID_LEN);
        pred.ip= value->node->address;
        pred.port= value->node->port;
    }

    return pred;    
}

vector<Node> * RPCClient::get_successor_list(Node succ)
{
    vector<Node> * succ_list= new vector<Node>();

    int sockfd= Transport::get_conn(succ.ip.c_str(), succ.port);
    if (sockfd == -1)
    {
        std::cout << "get_conn() error" << std::endl;
        return NULL;
    }
    
    
    // Serialize the call and send to remote node
    Protocol__GetSuccessorListArgs args= PROTOCOL__GET_SUCCESSOR_LIST_ARGS__INIT;
    
    size_t argsSerialLen= protocol__get_successor_list_args__get_packed_size(&args);
    uint8_t *argsSerial= (uint8_t *)malloc(argsSerialLen);

    protocol__get_successor_list_args__pack(&args, argsSerial);

    int err= 0;
    Protocol__Return *ret= NULL;
    err= make_call(argsSerialLen, argsSerial, &ret, "getsuccessorlist", sockfd);
    if (err)
    {
        std::cout << "make_call() error" << std::endl;
        return NULL;
    }
    

    Transport::close_conn(sockfd);
    
    // Return the value received 
    Protocol__GetSuccessorListRet *value = protocol__get_successor_list_ret__unpack(NULL, ret->value.len, ret->value.data);
    
    if (ret->success) 
    {
        for (int i= 0; i < (int) value->n_successors; i++)
        {
            Node n;
            memcpy(n.id, value->successors[i]->id.data, ID_LEN);
            n.ip= value->successors[i]->address;
            n.port= value->successors[i]->port;
            succ_list->push_back(n);
        }
    }

    return succ_list;    
}

void RPCClient::notify(Node succ, Node n)
{
    int sockfd= Transport::get_conn(succ.ip.c_str(), succ.port);
    if (sockfd == -1)
    {
        std::cout << "get_conn() error" << std::endl;
        return;
    }
    
    // Serialize the call and send to remote node
    Protocol__Node node= PROTOCOL__NODE__INIT;
    node.id.data= n.id;
    node.id.len= ID_LEN;
    node.port= n.port;
    node.address= (char *)n.ip.c_str();

    Protocol__NotifyArgs args= PROTOCOL__NOTIFY_ARGS__INIT;
    args.node= &node;
    
    size_t argsSerialLen = protocol__notify_args__get_packed_size(&args);
    uint8_t *argsSerial = (uint8_t *)malloc(argsSerialLen);

    protocol__notify_args__pack(&args, argsSerial);

    int err= 0;
    Protocol__Return *ret= NULL;
    err= make_call(argsSerialLen, argsSerial, &ret, "notify", sockfd);
    if (err)
    {
        std::cout << "make_call() error" << std::endl;
        return;
    }
    

    Transport::close_conn(sockfd);
    
    // Return the value received 
    Protocol__NotifyRet *value = protocol__notify_ret__unpack(NULL, ret->value.len, ret->value.data); 
    protocol__notify_ret__free_unpacked(value, NULL);
}

int RPCClient::check_predecessor(Node pred)
{
    int error= 0;

    int sockfd= Transport::get_conn(pred.ip.c_str(), pred.port);
    if (sockfd < 0)
        error= 1;
    else
    {
        // Serialize the call and send to remote node
        Protocol__CheckPredecessorArgs args = PROTOCOL__CHECK_PREDECESSOR_ARGS__INIT;

        size_t argsSerialLen = protocol__check_predecessor_args__get_packed_size(&args);
        uint8_t *argsSerial = (uint8_t *)malloc(argsSerialLen);

        protocol__check_predecessor_args__pack(&args, argsSerial);

        Protocol__Return *ret= NULL;
        make_call(argsSerialLen, argsSerial, &ret, "checkpredecessor", sockfd);
        Transport::close_conn(sockfd);
    }
    
    return error;    
}




