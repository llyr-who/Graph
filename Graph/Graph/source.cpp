#include<iostream>
#include "AdjMatrixGraph.h"
#include "AdjMatrixMultiGraph.h"
#include "AdjListGraph.h"
#include "search.h"
int main()
{
	AdjMatrixGraph graph(5,false);
	Edge e2(1, 3);
	graph.insert(e2);
	sPATH<AdjMatrixGraph> s(graph, 1,2);
	std::cout << s.exists() << std::endl;
	system("pause");
}