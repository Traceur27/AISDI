#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph
{
        struct vertex
        {
            int number;
            double x;
            double y;
            vector <pair<int,double> > edges;

            vertex(int _number, double _x, double _y) : number(_number), x(_x), y(_y) {};
        };

    vector<vertex> Vertices;
	int numberOfVertices;

public:
	void fill();
    void show();
    void add_edge(int first, int second, double weight);
	void transposition(Graph & before);
	friend void DFSstack(int v, bool * visited, stack<int> & S, Graph& graph);
	int howMany() {return numberOfVertices;};
	void Kosajaru();
	void DFSprint(int v, bool * visited, Graph& graf, list<int>& skladowe);
};
#endif // GRAPH_H
