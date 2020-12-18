#include <iostream>
#include <sstream>
#include <string>
#include <argp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <chord/argparser.hpp>
#include <chord/rpcserver.hpp>
#include <chord/hash.hpp>

#define verbose 0

//===============================================================
// Periodic Timer Functions (thread routines)
//===============================================================

static void * stabalize_timer(void *args)
{
    int msec= *((int *)args);
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000; 
    
    while (1)
    {
        nanosleep(&ts, &ts);
        if (verbose)
            cout << "[*]\tStabalizing..." << endl;
        Internal::stabalize();
    }
}

static void * checkpred_timer(void *args)
{
    int msec= *((int *)args);
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000; 
    
    while (1)
    {
        nanosleep(&ts, &ts);
        if (verbose)
            cout << "[*]\tChecking Predecessor..." << endl;
        Internal::check_predecessor();
    }
}

static void * fixfingers_timer(void *args)
{
    int msec= *((int *)args);
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000; 
    
    while (1)
    {
        nanosleep(&ts, &ts);
        if (verbose)
            cout << "[*]\tFixing Fingers..." << endl;
        Internal::fix_fingers();
    }
}

//===============================================================
// Helper Functions
//===============================================================

static void exit_withmsg(std::string msg)
{
    std::cout << "[Error]\t" << msg << std::endl;
    exit(1);
}


//===============================================================
// Chord Client Entry
//===============================================================

int main(int argc, char *argv[])
{
    /////////////////
    // parse arguments
    struct arguments args;
    struct argp_option options[]= {
        { "addr", 'a', "addr", 0, "The IP address the server is listening at", 0},
        { "port", 'p', "port", 0, "The port to be used for the server" ,0},
        { "ja", 300, "ja", 0, "The IP address of the machine running a Chord node" ,0},
        { "jp", 301, "jp", 0, "The port that an existing Chord node is bound to and listening on" ,0},
        { "ts", 302, "ts", 0, "time in ms between invocations of stabalize()", 0},
        { "tff", 303, "tff", 0, "time in ms between invocations of fix_fingers()", 0},
        { "tcp", 304, "tcp", 0, "time in ms between invocations of check_predecessor()", 0},
        { "r", 'r', "r", 0, "number of successors maintained by the chord client", 0},
        { "i", 'i', "i", 0, "optional id to be assigned to the chord client (overrides hash)", 0},
        {0}};
    
    struct argp argp_settings= { options, parser, 0, 0, 0, 0, 0 };
    bzero(&args, sizeof(args));

    // default values before parsing
    args.r= 3;
    args.tcp= 3000;
    args.tff= 3000;
    args.ts= 3000;
    args.id= NULL;

    if (argp_parse(&argp_settings, argc, argv, 0, NULL, &args) != 0) 
        exit_withmsg("Error when parsing args");


    /////////////////
    // start the RPCServer to listen for incoming RPCs
    pthread_t servthread;
    int sockfd= -1;

    sockfd= RPCServer::init(args.addr, args.port);
    pthread_create(&servthread, NULL, RPCServer::listener, &sockfd);
 
 
    ///////////////
    // initialize local structures
    uint8_t checksum[20];
    std::stringstream input; 
    Node join_node;

    input << args.addr << ":" << args.port; 

    if (args.id == NULL) // check if id specified (-i arg)
    {
        struct sha1sum_ctx *ctx= sha1sum_create(NULL, 0);
        sha1sum_finish(ctx, (const uint8_t*)input.str().c_str(), strlen(input.str().c_str()), checksum);
        Internal::init_local(args.addr, checksum, args.port, args.r);
    }
    else
    {
        Internal::init_local(args.addr, args.id, args.port, args.r);
        free(args.id);
    }
    
    if (args.j_addr != NULL) // join a ring or create one
    {
        join_node.ip= args.j_addr;
        join_node.port= args.j_port;
        Internal::join(join_node);
    } else { Internal::create(); }


    /////////////////
    // start periodic functions
    // should definitely be using alarm() timers here
    pthread_t stabalize_tid;
    pthread_t checkpred_tid;
    pthread_t fixfingers_tid;

    pthread_create(&fixfingers_tid, NULL, fixfingers_timer, &args.tff); 
    pthread_create(&stabalize_tid, NULL, stabalize_timer, &args.ts);
    pthread_create(&checkpred_tid, NULL, checkpred_timer, &args.tcp);


    /////////////////
    // start command loop
    string line;
    string tok;
    int pos;

    while (1)
    {
        cout << "> ";
        getline(cin, line);
        pos= line.find(" ");
        tok= line.substr(0, pos);
        line.erase(0, pos + 1);

        if (tok == "PrintState")
            Internal::print_state();
            
        else if (tok == "Lookup")
        {
            tok= line.substr(0, line.find(" "));
            struct sha1sum_ctx *ctx= sha1sum_create(NULL, 0);
            sha1sum_finish(ctx, (const uint8_t*)tok.c_str(), tok.length(), checksum);
            cout << "< " << tok << " ";
            for(size_t i = 0; i < ID_LEN; ++i) 
                printf("%02x", checksum[i]);
            
            cout << endl;
            Internal::lookup(checksum);
        }
    }  

    /////////////////
    // clean up (shouldn't reach here)
    pthread_join(servthread, NULL);
    pthread_join(stabalize_tid, NULL);
    pthread_join(checkpred_tid, NULL);
    pthread_join(fixfingers_tid, NULL);
}