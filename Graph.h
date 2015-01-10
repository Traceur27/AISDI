#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

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

public:
    Graph();
    //~Graph();
    void show();
    void add_edge(int first, int second, double weight);
};
#endif // GRAPH_H
