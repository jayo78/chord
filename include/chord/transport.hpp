#pragma once

#include <arpa/inet.h>
#include <stddef.h>
#include <stdint.h>


//=====================================================================================
// Transport - Get Connections and Send Data to Remote Nodes
//=====================================================================================

namespace Transport
{
    // attempt to connect to the addr arg and return a sockfd
    int get_conn(const char *ip, int port);
    void close_conn(int sockfd);
    int send_RPC(int sockfd, uint64_t len, uint8_t *data); // FREE DATA HERE
    uint8_t * recv_RPC(int sockfd, uint64_t *len);
}; // namespace RPCServer