#include<iostream>
#include "AdjListGraph.h"
#include "search.h"
int main()
{
  AdjListGraph graph(5);
  Edge e1(1, 4);
  Edge e2(0, 3);
  Edge e3(3, 4);
  Edge e4(0, 2);
  graph.insert(e1);
  graph.insert(e2);
  graph.insert(e3);

  sPATH<AdjListGraph> s(graph, 1,2);
  if(s.exists())
    std::cout << "connection has been found" << std::endl;
}
