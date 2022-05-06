# Executable Name
EXENAME = finalproj

# Object Types
OBJS = readFromFile.o graph.o Traversal.o BFS.o IDDFS.o dijkstra.o main.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp readFromFile.o graph.o Traversal.o BFS.o IDDFS.o dijkstra.o
	$(CXX) $(CXXFLAGS) main.cpp

readFromFile.o: readFromFile.cpp readFromFile.hpp
	$(CXX) $(CXXFLAGS) readFromFile.cpp
	
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp
	
BFS.o: BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

Traversal.o: Traversal.cpp Traversal.h
	$(CXX) $(CXXFLAGS) Traversal.cpp

IDDFS.o: IDDFS.cpp IDDFS.h
	$(CXX) $(CXXFLAGS) IDDFS.cpp

dijkstra.o: dijkstra.cpp dijkstra.h
	$(CXX) $(CXXFLAGS) dijkstra.cpp

test: output_msg catchmain.o test_graph.o test_BFS.o test_dijkstra.o test_IDDFS.o readFromFile.o graph.o Traversal.o BFS.o IDDFS.o dijkstra.o
	$(LD) catchmain.o test_graph.o test_BFS.o test_dijkstra.o test_IDDFS.o readFromFile.o graph.o Traversal.o BFS.o IDDFS.o dijkstra.o $(LDFLAGS) -o test

catchmain.o: catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

test_graph.o: tests/test_graph.cpp catch/catchmain.cpp readFromFile.o graph.o
	$(CXX) $(CXXFLAGS) tests/test_graph.cpp

test_BFS.o: tests/test_BFS.cpp catch/catchmain.cpp readFromFile.o graph.o Traversal.o BFS.o
	$(CXX) $(CXXFLAGS) tests/test_BFS.cpp

test_dijkstra.o: tests/test_dijkstra.cpp catch/catchmain.cpp readFromFile.o graph.o Traversal.o BFS.o dijkstra.o
	$(CXX) $(CXXFLAGS) tests/test_dijkstra.cpp

test_IDDFS.o: tests/test_IDDFS.cpp catch/catchmain.cpp readFromFile.o graph.o Traversal.o BFS.o IDDFS.o dijkstra.o
	$(CXX) $(CXXFLAGS) tests/test_IDDFS.cpp

clean:
	-rm -f *.o $(EXENAME) test
