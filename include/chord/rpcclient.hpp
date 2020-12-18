#pragma once

#include <stdint.h>

#include "node.hpp"

#include "../../chord.pb-c.h"

//===============================================================
// RPCClient for Handling Outgoing RPCs to Remote Nodes
//===============================================================

namespace RPCClient
{
    // ask node n to find and return the successor of key
    Node find_successor(Node n, uint8_t *key);
    // notify node succ that we are their predecessor
    void notify(Node succ, Node n);
    // check our predecessor, pred, is still alive
    int check_predecessor(Node pred);
    // ask node succ to tell us their predecessor
    Node get_predecessor(Node succ);
    // ask node succ for their successor list
    vector<Node> * get_successor_list(Node succ);
}; // namespace RPCClient
