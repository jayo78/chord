#include <string.h>
#include <iostream>
#include <pthread.h>

#include <chord/node.hpp>
#include <chord/finger.hpp>
#include <chord/rpcclient.hpp>


//=====================================================================================
// Helpers
//=====================================================================================

static int is_equal(uint8_t *a, uint8_t *b)
{
    return memcmp(a, b, ID_LEN) == 0;
}

static int between(uint8_t *key, uint8_t *a, uint8_t *b)
{
    int n= memcmp(a, b, ID_LEN);
    
    if (n == 0)
        return memcmp(a, key, ID_LEN) != 0;
    else if (n > 0)
        return memcmp(a, key, ID_LEN) < 0 || memcmp(b, key, ID_LEN) >= 0;
    else
        return memcmp(a, key, ID_LEN) < 0 && memcmp(b, key, ID_LEN) >= 0;
    
}

static int between_rightinc(uint8_t *key, uint8_t *a, uint8_t *b)
{
    return between(key, a, b) || is_equal(key, b);
}

static void print_id(uint8_t *id)
{
    for(size_t i = 0; i < ID_LEN; ++i) 
        printf("%02x", id[i]);
}

//=====================================================================================
// Structures, Data, and Functions for the Local Chord Client
//=====================================================================================

struct LocalClient
{
    Node local_node; 
    int num_succs;
    vector<Node> succs;
    vector<Node> finger_table;
    Node pred;

    pthread_mutex_t succ_mtx; // when modifying successor list
    pthread_mutex_t pred_mtx; // when modifying predecessor 
};

// global LocalClient struct that holds information for the local chord client
static LocalClient g_client;


//=====================================================================================
// Internal Functions that Operate on Local Structures
//=====================================================================================

void Internal::init_local(string ip, uint8_t *id, int port, int nsuccs)
{
    g_client.local_node.ip= ip;
    memcpy(g_client.local_node.id, id, ID_LEN);
    g_client.local_node.port= port;
    g_client.num_succs= nsuccs;

    pthread_mutex_init(&g_client.pred_mtx, NULL); 
    pthread_mutex_init(&g_client.succ_mtx, NULL);
}

// Fig. 6 join implementation 
void Internal::join(Node n)
{
    Node succ;

    succ= RPCClient::find_successor(n, g_client.local_node.id);

    for (int i= 0; i < g_client.num_succs; i++) // init structs with remote node 
        g_client.succs.push_back(succ);

    for (int i= 0; i < M; i++) // init structs with remote node 
        g_client.finger_table.push_back(succ);
}

// Fig. 6 create implementation
void Internal::create()
{
    for (int i= 0; i < g_client.num_succs; i++)  // init structs with our own node
        g_client.succs.push_back(g_client.local_node);

    for (int i= 0; i < M; i++)  // init structs with our own node
        g_client.finger_table.push_back(g_client.local_node);
}

// Print our successor list and finger table
void Internal::print_state()
{
    cout << "< Self ";
    print_id(g_client.local_node.id);
    cout << " " << g_client.local_node.ip << " " << g_client.local_node.port << endl;

    for (int i= 0; i < g_client.num_succs; i++)
    {
        cout << "< Successor[" << i+1 << "] ";
        print_id(g_client.succs[i].id);
        cout << " " << g_client.succs[i].ip << " " << g_client.succs[i].port << endl;
    }
    for (int i= 0; i < M; i++)
    {
        cout << "< Finger[" << i+1 << "] ";
        print_id(g_client.finger_table[i].id);
        cout << " " << g_client.finger_table[i].ip << " " << g_client.finger_table[i].port << endl;
    }
}

// Find the node that holds a given key
void Internal::lookup(uint8_t *key)
{
    Node succ;

    succ= RPCClient::find_successor(g_client.succs[0], key);
    cout << "< ";
    print_id(succ.id);
    cout << " " << succ.ip << " " << succ.port << endl;
}

// Fig. 5 closest_preceding_node implementation - checks both the successor list and finger table
Node Internal::closest_preceding_node(uint8_t *key)
{
    Node finger;
    for (int i= M - 1; i >= 0; i--)
    {
        finger= g_client.finger_table[i];
        if (between(key, finger.id, g_client.local_node.id))
            return finger;
    }

    Node succ;
    for(int i= 0; i < g_client.num_succs; i++)
    {
        succ= g_client.succs[i];
        if (between(key, g_client.local_node.id, succ.id))
            return succ;
    }
    
    return g_client.local_node; 
}

// Fig. 5 recursive find_successor implementation
Node Internal::find_successor(uint8_t *id)
{
    pthread_mutex_lock(&g_client.succ_mtx);

    Node result;
    Node pred;

    if (between_rightinc(id, g_client.local_node.id, g_client.succs[0].id))
        result= g_client.succs[0];
    else
    {
        pred= closest_preceding_node(id);
        if (pred.ip == g_client.local_node.ip && pred.port == g_client.local_node.port)
            result= g_client.local_node;
        else
            result= RPCClient::find_successor(pred, id); // ask a closer node (recursive)
    }
        
    pthread_mutex_unlock(&g_client.succ_mtx);
    return result;
}

// Fig. 6 stabalize implementation - extended to using a successor list in section E.3 Failure and Replication
void Internal::stabalize()
{
    Node succ;
    Node x;
    vector<Node> *succs= NULL;
    int i= 0;
    int index= 0;

    while (succs == NULL && i < g_client.num_succs) // get first live successor
        succs= RPCClient::get_successor_list(g_client.succs[i++]);

    index= i-1; 
    succs->pop_back(); // rm last elt
    succs->insert(succs->begin(), g_client.succs[index]); // prepend successor we asked        

    pthread_mutex_lock(&g_client.succ_mtx);
    g_client.succs.swap(*succs); // reconcile with our own successor list
    pthread_mutex_unlock(&g_client.succ_mtx);

    x= RPCClient::get_predecessor(g_client.succs[0]);
    if (!x.ip.empty() && between(x.id, g_client.local_node.id, g_client.succs[0].id))
    {
        pthread_mutex_lock(&g_client.succ_mtx);
        g_client.succs.pop_back();
        g_client.succs.insert(g_client.succs.begin(), x);
        pthread_mutex_unlock(&g_client.succ_mtx);

    }


    // notify 
    RPCClient::notify(g_client.succs[0], g_client.local_node);
}

// Fig. 6 check_predecessor implementation
void Internal::check_predecessor()
{
    pthread_mutex_lock(&g_client.pred_mtx);

    int err= 0;

    if (!(g_client.pred.ip.empty()))
    {
        err= RPCClient::check_predecessor(g_client.pred);
        
        if (err)
            g_client.pred.ip= "";
    }

    pthread_mutex_unlock(&g_client.pred_mtx);
}

// Fig. 6 fix_fingers implementation
void Internal::fix_fingers()
{
    static int i= 0;
    Node next= g_client.finger_table[i];
    uint8_t nextHash[ID_LEN];
    uint8_t fid[ID_LEN];

    memcpy(nextHash, next.id, ID_LEN);
    finger_id(nextHash, i, fid); // fid now has the ID we want to find the successor for

    Node succ= RPCClient::find_successor(g_client.succs[0], fid);
    if (!succ.ip.empty())
        g_client.finger_table[i]= succ; 

    i++;
    if (i >= M)
        i= 0;
}


// Fig. 6 notify implementation
void Internal::notify(Node n)
{
    pthread_mutex_lock(&g_client.pred_mtx);
    
    if (g_client.pred.ip.empty() || between(n.id, g_client.pred.id, g_client.local_node.id))
        g_client.pred= n;

    // transfer keys here
    
    pthread_mutex_unlock(&g_client.pred_mtx);
}

Node Internal::get_predecessor()
{
    return g_client.pred;
}

vector<Node> * Internal::get_successor_list()
{
    return &g_client.succs;
}
