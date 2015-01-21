#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
		if(getchar() != '\n') //pobiera kolejne pary liczb do czasu natrafienia spacji dwóch cyfrach
			break;
        Vertices.push_back(vertex(i,a,b));
		++i;
    }
	numberOfVertices = i;
    int c, d;
    double e;
    c = (int) a; //w takim przypadku rzutuje dwie wartosci double na inty(z zalozen zadania wiemy ze musza byc to liczby calkowite) i pobiera trzecia
    d = (int) b;
    cin >> e;

    while(getchar() != EOF)
    {
		if(c > numberOfVertices || d > numberOfVertices) //sprawdzam czy ktos nie probuje dodac krawedzi z nieistniejacym wierzcholkiem
		{
			printf("Proba dodania krawedzi z nieistniejacym wierzcholkiem: %d -> %d (%f)\n",c,d,e);
			exit(1);
		}
        add_edge(c,d,e);
        cin >> c >> d >> e;
    }

}

void Graph::add_edge(int first, int second, double weight)
{
    vector<vertex>::iterator it;
    for(it = Vertices.begin(); it != Vertices.end(); ++it) //znajduje wierzcholek o podanym numerze
        if((*it).number == first)
            break;

	if(it != Vertices.end())
	{
		vector<pair<int,double> >::iterator itt;
		for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++itt)
			if((*itt).first == second)
				{
					(*itt).second = weight; //sprawdzam czy podana krawedz juz istnieje - jesli tak to nadpisuje jej wage
					return;
				}
	}
    (*it).edges.push_back(make_pair(second,weight));
    return;
}

void Graph::show() //wypisuje wszystkie krawedzie wraz z wagami
{
	vector<pair<int,double> >::iterator itt;
    vector<vertex>::iterator it;
    for(it = Vertices.begin(); it != Vertices.end(); ++it){
        cout << (*it).number << "   "; //<< (*it).y << "      " << (*((*it).edges.begin())).first << "    " << (*((*it).edges.begin())).second <<  endl;
		for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++itt)
		cout << (*itt).first << " waga: " <<  (*itt).second << " ";
		cout << "\n";
	}
}

void Graph::transposition(Graph & before)
{
	vector<vertex>::iterator it;
    for(it = before.Vertices.begin(); it != before.Vertices.end(); ++it) //podany graf wypelniam wierzcholkami takimi samymi jak zadany
		Vertices.push_back(vertex((*it).number,(*it).x,(*it).y));

	vector<pair<int,double> >::iterator itt;
	for(it = before.Vertices.begin(); it != before.Vertices.end(); ++it)
	{
		for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++itt)  //jezeli wierzcholek x mial krawedzie do y i z to w wierzcholki y i z wpisuje x
			add_edge((*itt).first, (*it).number, (*itt).second);
	}
}

void depthFirstTraversal(int v, bool * visited, stack<int> & S, Graph& graph)
{
	visited[v] = true;
	vector<Graph::vertex>::iterator it;
	for(it = graph.Vertices.begin(); it != graph.Vertices.end(); ++it) //znajduje wierzcholek o podanym numerze
	{
		if(v == (*it).number)
			break;
	}	
	vector<pair<int,double> >::iterator itt;
	for(itt = (*it).edges.begin(); itt != (*it).edges.end(); ++ itt)
	{
		if(!visited[(*itt).first]) 
			depthFirstTraversal((*itt).first, visited, S, graph); //przechodzac w glab wrzucam wierzcholki na stos
	}
	S.push(v);
}

void collectSCC(int v, bool * visited, Graph& graph, list<int>& skladowe)
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
			collectSCC((*itt).first, visited, graph, skladowe);
	}

}

void Graph::kosajaru()
{
	Graph two;
	two.transposition(*this);
	bool visited[this->howMany()];
	int i = 0;
	for(; i< this->howMany();++i)
		visited[i] = false;

	stack<int> S;
	for(i = 0; i< this->howMany();++i)
		if(!visited[i])
			depthFirstTraversal(i,visited, S, *this);

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
      		collectSCC(v,visited,two, skladowe);
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
