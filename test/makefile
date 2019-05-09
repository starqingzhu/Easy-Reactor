CXX=g++
CFLAGS=-g -std=c++11 -O2 -Wall -fPIC -Wno-deprecated

INC=-I../include
LIB=-L../lib -lereactor -lpthread  /usr/lib/libprotobuf.a -lrt
OBJS = $(addsuffix .o, $(basename $(wildcard *.cc)))

all:
	$(CXX) -o server.prog $(CFLAGS) server.cc echoMsg.pb.cc $(INC) $(LIB)
	$(CXX) -o benchmark.prog $(CFLAGS) benchmark.cc echoMsg.pb.cc $(INC) $(LIB)

proto:
	protoc --cpp_out=. echoMsg.proto
clean:
	rm -f *.o *.d server.prog benchmark.prog *.pb.*
