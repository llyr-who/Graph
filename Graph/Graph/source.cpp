#include<iostream>
#include"AdjListGraph.h"
int main()
{
	AdjListGraph graph(4,true);
	Edge e1(1, 2);
	Edge e2(1, 3);
	graph.insert(e1);
	graph.insert(e2);
	graph.remove(e1);
	system("pause");

}