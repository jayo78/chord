#pragma once

#include <vector>
#include <string>

using namespace std;

#define ID_LEN 20

// A Chord Node has an ip, port, and id
struct Node
{
    string ip;
    int port;
    uint8_t id[20];
}; // Node struct


//===============================================================
// Internal Functions that Execute the Chord Algorithms
//===============================================================

namespace Internal
{
    // initialized local structures
    void init_local(string ip, uint8_t *id, int port, int nsuccs);
    // join an existing chord ring
    void join(Node n);
    // create a new chord ring
    void create();
    // find the node that has a specified id
    void lookup(uint8_t *key);
    // print the state of local structures (finger table/successors)
    void print_state();
    Node closest_preceding_node(uint8_t *key);
    // ask node n to find and return the successor of id
    Node find_successor(uint8_t *id);
    // n thinks it might be our predecessor
    void notify(Node n);
    // reconcile our successor list
    void stabalize();
    // check our predecessor, pred, is still alive
    void check_predecessor();
    // fix our finger table one by one
    void fix_fingers();
    // get our predecessor
    Node get_predecessor();
    // ask node 
    vector<Node> * get_successor_list();
};