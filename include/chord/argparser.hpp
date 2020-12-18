#pragma once

#include <stdint.h>
#include <arpa/inet.h>
#include <errno.h>

struct arguments 
{
	char *addr;   // address of the chord client
	int port;
    char *j_addr; // address of a machine running a chord node (will join ring)
    int j_port;
    uint32_t ts;                // time in ms between invocations of stabalize()
    uint32_t tff;               // time in ms between invocations of fix_fingers()
    uint32_t tcp;               // time in ms between invocations of check_predecessor()
    uint32_t r;                 // number of successors maintained by the chord client
    uint8_t *id;             // optional id to be assigned to the chord client (overrides hash)
};

error_t parser(int key, char *arg, struct argp_state *state);