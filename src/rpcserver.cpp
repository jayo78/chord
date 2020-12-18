#include <iostream>
#include <pthread.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#include <chord/rpcserver.hpp>
#include <chord/node.hpp>
#include <chord/transport.hpp>

#include "../chord.pb-c.h" // protobuf-c defs


//=====================================================================================
// RPC Interface Functions - call internal functions (see node.hpp)
//=====================================================================================

static int _find_successor(uint8_t **valueSerial, size_t *valueSerialLen, const uint8_t *argsSerial, size_t argsSerialLen)
{
    int error= 0;

    // Deserialize/Unpack the arguments
    Protocol__FindSuccessorArgs *args= protocol__find_successor_args__unpack(NULL, argsSerialLen, argsSerial);
    if(args == NULL)
        return 1;

    // Call the underlying function
    Node succ= Internal::find_successor(args->id.data);

    Protocol__FindSuccessorRet value= PROTOCOL__FIND_SUCCESSOR_RET__INIT;

    Protocol__Node pnode= PROTOCOL__NODE__INIT;
    pnode.address= (char *) succ.ip.c_str();
    pnode.id.data= succ.id;
    pnode.id.len= ID_LEN;
    pnode.port= succ.port;

    value.node= &pnode;

    *valueSerialLen= protocol__find_successor_ret__get_packed_size(&value);
    *valueSerial= (uint8_t *)malloc(*valueSerialLen);
    if (*valueSerial == NULL) {
        error = 1;
        goto errValueMalloc;
    }

    protocol__find_successor_ret__pack(&value, *valueSerial);

    // Cleanup
  errValueMalloc:
    protocol__find_successor_args__free_unpacked(args, NULL);

    return error;
}

static int _check_predecessor(uint8_t **valueSerial, size_t *valueSerialLen, const uint8_t *argsSerial, size_t argsSerialLen)
{
    int error= 0;

    // Deserialize/Unpack the arguments
    Protocol__CheckPredecessorArgs *args= protocol__check_predecessor_args__unpack(NULL, argsSerialLen, argsSerial);
    if(args == NULL)
        return 1;
    

    Protocol__CheckPredecessorRet value= PROTOCOL__CHECK_PREDECESSOR_RET__INIT;

    *valueSerialLen= protocol__check_predecessor_ret__get_packed_size(&value);
    *valueSerial= (uint8_t *)malloc(*valueSerialLen);
    if (*valueSerial == NULL) {
        error= 1;
        goto errValueMalloc;
    }

    protocol__check_predecessor_ret__pack(&value, *valueSerial);

    // Cleanup
  errValueMalloc:
    protocol__check_predecessor_args__free_unpacked(args, NULL);

    return error;
}

static int _get_predecessor(uint8_t **valueSerial, size_t *valueSerialLen, const uint8_t *argsSerial, size_t argsSerialLen)
{
    int error= 0;

    // Deserialize/Unpack the arguments
    Protocol__GetPredecessorArgs *args= protocol__get_predecessor_args__unpack(NULL, argsSerialLen, argsSerial);
    if(args == NULL)
        return 1;

    // Call the underlying function
    Node pred= Internal::get_predecessor();

    Protocol__GetPredecessorRet value= PROTOCOL__GET_PREDECESSOR_RET__INIT;

    Protocol__Node pnode= PROTOCOL__NODE__INIT;
    pnode.address= (char *) pred.ip.c_str();
    pnode.id.data= pred.id;
    pnode.id.len= ID_LEN;
    pnode.port= pred.port;

    value.node= &pnode;

    *valueSerialLen= protocol__get_predecessor_ret__get_packed_size(&value);
    *valueSerial= (uint8_t *)malloc(*valueSerialLen);
    if (*valueSerial == NULL) {
        error = 1;
        goto errValueMalloc;
    }

    protocol__get_predecessor_ret__pack(&value, *valueSerial);

    // Cleanup
  errValueMalloc:
    protocol__get_predecessor_args__free_unpacked(args, NULL);

    return error;
}

static int _get_successor_list(uint8_t **valueSerial, size_t *valueSerialLen, const uint8_t *argsSerial, size_t argsSerialLen)
{
    int error= 0;

    // Deserialize/Unpack the arguments
    Protocol__GetSuccessorListArgs *args= protocol__get_successor_list_args__unpack(NULL, argsSerialLen, argsSerial);
    if(args == NULL)
        return 1;
    
    // Call the underlying function
    vector<Node> *list= Internal::get_successor_list();

    Protocol__GetSuccessorListRet value= PROTOCOL__GET_SUCCESSOR_LIST_RET__INIT;
    Protocol__Node **succ_list;
    succ_list= (Protocol__Node **) malloc(sizeof(Protocol__Node*) * list->size());

    for (int i= 0; i < (int) list->size(); i++)
    {
        succ_list[i]= (Protocol__Node *) malloc(sizeof(Protocol__Node));
        *(succ_list[i])= PROTOCOL__NODE__INIT;
        succ_list[i]->address= (char *) (*list)[i].ip.c_str();
        succ_list[i]->id.data= (*list)[i].id;
        succ_list[i]->id.len= ID_LEN;
        succ_list[i]->port= (*list)[i].port;
    }

    value.successors= succ_list;
    value.n_successors= list->size();

    *valueSerialLen= protocol__get_successor_list_ret__get_packed_size(&value);
    *valueSerial= (uint8_t *)malloc(*valueSerialLen);
    if (*valueSerial == NULL) {
        error = 1;
        goto errValueMalloc;
    }

    protocol__get_successor_list_ret__pack(&value, *valueSerial);

    // Cleanup
  errValueMalloc:
    protocol__get_successor_list_args__free_unpacked(args, NULL);

    for (int i= 0; i < (int) list->size(); i++)
        free(succ_list[i]);
    free(succ_list);
    

    return error;
}     

static int _notify(uint8_t **valueSerial, size_t *valueSerialLen, const uint8_t *argsSerial, size_t argsSerialLen)
{ 
    int error= 0;

    // Deserialize/Unpack the arguments
    Protocol__NotifyArgs *args= protocol__notify_args__unpack(NULL, argsSerialLen, argsSerial);
    if(args == NULL)
        return 1;

    Node n;
    memcpy(n.id, args->node->id.data, ID_LEN);
    n.ip= args->node->address;
    n.port= args->node->port;

    // Call the underlying function
    Internal::notify(n);

    Protocol__NotifyRet value= PROTOCOL__NOTIFY_RET__INIT;

    *valueSerialLen= protocol__notify_ret__get_packed_size(&value);
    *valueSerial= (uint8_t *)malloc(*valueSerialLen);
    if (*valueSerial == NULL) {
        error = 1;
        goto errValueMalloc;
    }

    protocol__notify_ret__pack(&value, *valueSerial);

    // Cleanup
  errValueMalloc:
    protocol__notify_args__free_unpacked(args, NULL);

    return error;
}


//=====================================================================================
// Handling and Parsing 
//=====================================================================================

// unpack an RPC call, pass it to the appropriate wrapper function, and pack its return value
static int parse_call(uint8_t **retSerial, size_t *retSerialLen, const uint8_t *callSerial, size_t callSerialLen)
{
    int error= 0;

    // Deserializing/Unpacking the call
    Protocol__Call *call= protocol__call__unpack(NULL, callSerialLen, callSerial);
    if (call == NULL) 
        return 1;

    // Calling the appropriate wrapper function based on the `name' field
    uint8_t *valueSerial;
    size_t valueSerialLen;
    bool success;

    if (strcmp(call->name, "findsuccessor") == 0) 
        success= !_find_successor(&valueSerial, &valueSerialLen, call->args.data, call->args.len);
    else if (strcmp(call->name, "checkpredecessor") == 0)
        success= !_check_predecessor(&valueSerial, &valueSerialLen, call->args.data, call->args.len);    
    else if (strcmp(call->name, "getsuccessorlist") == 0)
        success= !_get_successor_list(&valueSerial, &valueSerialLen, call->args.data, call->args.len);
    else if (strcmp(call->name, "notify") == 0)
        success= !_notify(&valueSerial, &valueSerialLen, call->args.data, call->args.len);
    else if (strcmp(call->name, "getpredecessor") == 0)
        success= !_get_predecessor(&valueSerial, &valueSerialLen, call->args.data, call->args.len);
    else 
    {
        protocol__call__free_unpacked(call, NULL);
        return 1;
    }

    // Serializing/Packing the return, using the return value from the invoked function
    Protocol__Return ret= PROTOCOL__RETURN__INIT;
    ret.success= success;
    if (success) {
        ret.value.data= valueSerial;
        ret.value.len= valueSerialLen;
        ret.has_value= 1;
    }

    *retSerialLen= protocol__return__get_packed_size(&ret);
    *retSerial= (uint8_t *)malloc(*retSerialLen);
    if (*retSerial == NULL) {
        error= 1;
        goto errRetMalloc;
    }
    
    protocol__return__pack(&ret, *retSerial);

    // Cleanup
  errRetMalloc:
    if (success) {
        free(valueSerial);
    }

    return error;
}

// receive RPC call from socket, parse it, and then send the return back
static int handle_RPC(int sockfd)
{
    int err= 0;
    uint64_t len;
    uint8_t *data= NULL;

    // get the RPC raw bytes from socket - stored in data
    data= Transport::recv_RPC(sockfd, &len);
    if (data == NULL)
    {
        std::cout << "[-]\tError recving RPC" << std::endl;
        return 1;
    }
        
    size_t retSerialLen;
    uint8_t *retSerial;

    // retSerial will contain the value we want to return to the socket
    err= parse_call(&retSerial, &retSerialLen, data, len);
    if (err)
    {
        std::cout << "[-]\tError parsing the call" << std::endl;
        return 1;
    }

    // send the RPC return value
    err= Transport::send_RPC(sockfd, retSerialLen, retSerial);
    if (err)
    {
        std::cout << "[-]\tError sending the return" << std::endl;
        return 1;
    }

    free(retSerial);
    free(data);

    return err;
}

static void exit_withmsg(std::string msg)
{
    std::cout << "[Error]\t" << msg << std::endl;
    exit(1);
}


//=====================================================================================
// Server Init and Listener
//=====================================================================================

// thread listens for client connects to then handle their RPC request
void * RPCServer::listener(void *args)
{
    int err= 0;
    int sockfd= *((int *)args);
    int cli_sockfd= -1;
    socklen_t cli_addrlen;
    sockaddr_in cli_addr;

    cli_addrlen= sizeof(cli_addr);
    while (1)
    {  
        cli_sockfd= accept(sockfd, (sockaddr *) &cli_addr, &cli_addrlen);
        
        err= handle_RPC(cli_sockfd);
        if (err)
            std::cout << "[-]\tError handling the RPC ... Closing socket" << std::endl;

        close(cli_sockfd);
    }
}

// start server by creating thread with listener() as its routine
int RPCServer::init(char *ip, int port)
{
    int sockfd= -1;
    sockaddr_in addr;

    addr.sin_family= AF_INET;
    addr.sin_addr.s_addr= inet_addr(ip);
    addr.sin_port= htons(port);

    sockfd= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
        exit_withmsg("socket() failed - sockfd");
    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        exit_withmsg("setsockopt(SO_REUSEADDR) failed");
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0)
        exit_withmsg("bind() failed");
    if (listen(sockfd, 10) < 0)
        exit_withmsg("listen() failed");

    return sockfd;
}

