
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include <chord/transport.hpp>


//=====================================================================================
// Send/Recv Wrappers
//=====================================================================================

static int send_all(int socket, const void *buffer, size_t length, int flags)
{
    ssize_t n;
    char *p= (char *) buffer;
    while (length > 0)
    {
        n= send(socket, p, length, flags);
        if (n <= 0)
            return -1;
        p+= n;
        length-= n;
    }
    return length;
}

static int recv_all(int socket, void *buffer, size_t length, int flags)
{
    ssize_t n;
    char *p= (char *) buffer;
    while (length > 0)
    {
        n= recv(socket, p, length, flags);
        if (n <= 0)
            return -1;
        p+= n;
        length-= n;
    }
    return length;
}


//=====================================================================================
// Transport - Get Connections and Send Data to Remote Nodes
//=====================================================================================

void Transport::close_conn(int sockfd)
{
    if (sockfd != -1)
        close(sockfd);
}

int Transport::get_conn(const char *ip, int port)
{
    sockaddr_in addr;
    int sockfd= -1;

    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr= inet_addr(ip);
    addr.sin_family= AF_INET;
    addr.sin_port= htons(port);

    sockfd= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        return -1;

    return sockfd;
}

int Transport::send_RPC(int sockfd, uint64_t len, uint8_t *data)
{
    int error= 0;
    uint8_t *sendbuf;
    uint64_t tlen; // total len

    tlen= 8 + len;
    sendbuf= (uint8_t*)malloc(tlen);

    memcpy(sendbuf+8, data, len);
    len= htobe64(tlen);
    memcpy(sendbuf, &len, 8);
    
    if (send_all(sockfd, sendbuf, tlen, 0) == -1)
        error= 1;

    free(sendbuf);
    
    return error;
}

uint8_t * Transport::recv_RPC(int sockfd, uint64_t *len)
{
    int error= 0;
    uint8_t *data;

    error= recv_all(sockfd, len, 8, 0); // recv the packet len first
    if (error)
        return NULL;

    *len= be64toh(*len) - 8;
    data= (uint8_t *)malloc(*len);
    
    error= recv_all(sockfd, data, *len, 0);
    if (error)
        return NULL;

    return data;
}


