#include <iostream>
#include <stdio.h>
#include "Graph.h"

using namespace std;

Graph::Graph()
{
    double a, b;
	int i = 0;
    while(1)
    {
        cin >> a >> b;
		if(getchar() != '\n')
			break;
        Vertices.push_back(vertex(i,a,b));
		++i;
    }
    int c, d;
    double e;
    c = (int) a;
    d = (int) b;
    cin >> e;

    while(getchar() != EOF)
    {
        add_edge(c,d,e);
        cin >> c >> d >> e;
    }

}

void Graph::add_edge(int first, int second, double weight)
{
    vector<vertex>::iterator it;
    for(it = Vertices.begin(); it != Vertices.end(); ++it)
        if((*it).number == first)
            break;
	if(it != Vertices.end())
    (*it).edges.push_back(make_pair(second,weight));
    return;
}

void Graph::show()
{
    vector<vertex>::iterator it;
    for(it = Vertices.begin(); it != Vertices.end(); ++it)
        cout << (*it).x << "   " << (*it).y << "      " << (*((*it).edges.begin())).first << "    " << (*((*it).edges.begin())).second <<  endl;
}

