CXX=g++
CFLAGS=-g -std=c++11 -O2 -Wall -fPIC -Wno-deprecated

INC=-I../../include
LIB=-L../../lib -lereactor -lpthread -lrt
OBJS = $(addsuffix .o, $(basename $(wildcard *.cc)))

all:
	$(CXX) -o server.prog $(CFLAGS) server.cc $(INC) $(LIB)

clean:
	-rm -f *.o *.d server.prog
