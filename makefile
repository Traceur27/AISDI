CXX=g++
OBJS = Graph.o main.o
CFLAGS=-c -Wall

all: graph

graph: $(OBJS)
	$(CXX) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf *o hello

.PHONY: all clean
