#pragma once

#include "node.hpp"


//===============================================================
// RPCServer for Handling Incoming RPCs from Remote Nodes
//===============================================================

namespace RPCServer
{
    // start/stop a listener thread
    void * listener(void *args);
    int init(char *ip, int port);     
    
}; // namespace RPCServer

