#include<iostream>
#include "AdjMatrixGraph.h"
#include "AdjMatrixMultiGraph.h"
#include "AdjListGraph.h"
#include "search.h"
int main()
{
	AdjListGraph graph(5,false);
	Edge e2(1, 3);
	Edge e3(2, 4);
	Edge e4(1, 0);
	graph.insert(e2);
	graph.insert(e3);
	graph.insert(e4);
	sPATH<AdjListGraph> s(graph, 1,2);
	std::cout << s.exists() << std::endl;
	system("pause");
}