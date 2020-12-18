#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <argp.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <chord/argparser.hpp>
#include <chord/node.hpp>

error_t parser(int key, char *arg, struct argp_state *state) {
	struct arguments *args = (struct arguments *) state->input;
	error_t ret = 0;

	switch(key) {
        case 'a': 
            args->addr= arg;
            
            break;
        case 'p': 
            args->port= atoi(arg);
            
            break;
        case 300: 
            args->j_addr= arg;
        
            break;
        case 301: 
            args->j_port= atoi(arg);
            
            break;
        case 302:
            args->ts= atoi(arg);

            if (args->ts < 1 || args->ts > 60000)
                argp_error(state, "Invalid ts");
            
            break;
        case 303:
            args->tff= atoi(arg);

            if (args->tff < 1 || args->tff > 60000)
                argp_error(state, "Invalid tff");
            
            break;
        case 304:
            args->tcp= atoi(arg);

            if (args->tcp < 1 || args->tcp > 60000)
                argp_error(state, "Invalid tcp");
            
            break;
        case 'r':
            args->r= atoi(arg);

            if (args->r < 1 || args->r > 32)
                argp_error(state, "Invalid r");
            
            break;
        case 'i':
            args->id= (uint8_t *) malloc(strlen(arg));
            memcpy(args->id, arg, ID_LEN);
            break;

        default:
            ret = ARGP_ERR_UNKNOWN;
            break;
	}
	return ret;
}