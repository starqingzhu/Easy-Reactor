CXX=g++
CFLAGS=-g -O2 -Wall -fPIC -Wno-deprecated -std=c++11

INC=-I../../include
LIB=-L../../lib -lereactor /usr/lib/libprotobuf.a -lrt
OBJS = $(addsuffix .o, $(basename $(wildcard *.cc)))

all:
	$(CXX) -o server.prog $(CFLAGS) server.cc echoMsg.pb.cc $(INC) $(LIB)
	$(CXX) -o client.prog $(CFLAGS) client.cc echoMsg.pb.cc $(INC) $(LIB)

clean:
	rm -f *.o *.d server client *.pb.*

proto:
	protoc --cpp_out=. echoMsg.proto
