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
	void fill(); //pobiera dane ze standardowego wejscia i wypelnia nimi graf
    void show(); //wypisuje zawartosc grafu wraz z wagami krawedzi
    void add_edge(int first, int second, double weight); //dodaje krawedz; w przypadku proby dodania tej samej krawedzi zmienia jej wage
	void transposition(Graph & before); //transpozycja grafu - potrzebna w algorytmie Kosajaru
	friend void depthFirstTraversal(int v, bool * visited, stack<int> & S, Graph& graph); //przejscie grafu wglab z wrzuceniem na stos odwiedzonych wierzcholkow
	int howMany() {return numberOfVertices;}; //zwraca liczbe wierzcholkow
	void kosajaru();
	friend void collectSCC(int v, bool * visited, Graph& graf, list<int>& skladowe); //przechodzi przez graf ktory zostal poddany transpozycji
																				   //zapisujac silnie spojne skladowe 
};
#endif // GRAPH_H
