CFLAGS= -Wall -Iinclude -g
CC= g++

LIB_A= libchord.a

LIB_OBJS= $(addprefix src/, \
	argparser.o \
	node.o \
	finger.o \
	transport.o \
	rpcserver.o \
	rpcclient.o \
	hash.o)

PROG_OBJS= $(addprefix src/, \
	main.o)

OBJS= $(LIB_OBJS) $(PROG_OBJS)

HEADERS= $(addprefix include/chord/, \
	argparser.hpp \
	node.hpp \
	finger.hpp \
	transport.hpp \
	rpcserver.hpp \
	rpcclient.hpp \
	hash.hpp)

all: chord

$(OBJS): src/%.o: src/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_A): $(LIB_OBJS)
	ar cr $@ $^
	ranlib $@

# build the auto generated protobuff source files
chord.pb-c.o: chord.pb-c.c chord.pb-c.h chord.proto
	$(CC) -c -o $@ $<

# build the main chord p2p client
chord: src/main.o chord.pb-c.o $(LIB_A)
	$(CC) -o $@ $^ -lprotobuf-c -lpthread -lcrypto -lgmp

clean:
	rm -f $(OBJS) $(LIB_A) chord chord.pb-c.o