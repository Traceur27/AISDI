#include <iostream>
#include <stdio.h>
#include <stack>
#include <list>
#include "Graph.h"

using namespace std;

void Graph::fill()
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
	numberOfVertices = i;
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
	vector<pair<int,double> >::iterator itt;
    vector<vertex>::iterator it;
    for(it = Vertices.begin(); it != Vertices.end(); ++it){
        cout << (*it).number << "   "; //<< (*it).y << "      " << (*((*it).edges.begin())).first << "    " << (*((*it).edges.begin())).second <<  endl;
		for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++itt)
		cout << (*itt).first;
		cout << "\n";
	}
}

void Graph::transposition(Graph & before)
{
	vector<vertex>::iterator it;
    for(it = before.Vertices.begin(); it != before.Vertices.end(); ++it)
		Vertices.push_back(vertex((*it).number,(*it).x,(*it).y));

	vector<pair<int,double> >::iterator itt;
	for(it = before.Vertices.begin(); it != before.Vertices.end(); ++it)
	{
		for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++itt)
			add_edge((*itt).first, (*it).number, (*itt).second);
	}
}

void DFSstack(int v, bool * visited, stack<int> & S, Graph& graph)
{
	visited[v] = true;
	vector<Graph::vertex>::iterator it;
	for(it = graph.Vertices.begin(); it != graph.Vertices.end(); ++it)
	{
		if(v == (*it).number)
			break;
	}	
	vector<pair<int,double> >::iterator itt;
	for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++ itt)
	{
		if(!visited[(*itt).first]) 
			DFSstack((*itt).first, visited, S, graph);
	}
	S.push(v);
}

void Graph::DFSprint(int v, bool * visited, Graph& graph, list<int>& skladowe)
{
	visited[v] = true;
	skladowe.push_back(v);
	vector<Graph::vertex>::iterator it;
	for(it = graph.Vertices.begin(); it != graph.Vertices.end(); ++it)
	{
		if(v == (*it).number)
			break;
	}	
	vector<pair<int,double> >::iterator itt;
	for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++ itt)
	{
		if(!visited[(*itt).first]) 
			DFSprint((*itt).first, visited, graph, skladowe);
	}

}

void Graph::Kosajaru()
{
	Graph two;
	two.transposition(*this);
	bool visited[this->howMany()];
	int i = 0;
	for(; i< this->howMany();++i)
		visited[i] = false;

	stack<int> S;
	DFSstack(0,visited, S, *this);

	for(i = 0; i< this->howMany();++i)
		visited[i] = false;


	int v = 0;
	list<int> skladowe;
	list<int>::iterator it;
	while(!S.empty())              
    {
    	v = S.top();
		S.pop();     
    	if(!visited[v])
    	{
      		DFSprint(v,visited,two, skladowe);
			if((skladowe.size() % 2) == 1)
			{
				for(it = skladowe.begin(); it != skladowe.end(); ++it)
					cout << *it << " ";
      		cout << endl;
			skladowe.clear();
			}
    	}
  	}

}
