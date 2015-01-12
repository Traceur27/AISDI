#include <iostream>
#include <stack>
#include "Graph.h"


using namespace std;

int main()
{
    Graph one;
	//Graph two;
	one.fill();
	/* two.transposition(one);
	bool visited[one.howMany()];
	int i = 0;
	for(; i< one.howMany();++i)
		visited[i] = false;
	stack<int> S;
	DFSstack(0,visited, S, one); */
    one.Kosajaru();
    cout << "Hello world!" << endl;
    return 0;
}

