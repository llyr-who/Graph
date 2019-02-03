#include<iostream>
#include "AdjListGraph.h"
#include "search.h"
int main()
{
  AdjListGraph graph(6);
  Edge e0(0, 1);
  Edge e1(0, 3);
  Edge e2(1, 2);
  Edge e3(2, 3);
  Edge e4(3, 4);
  Edge e5(4, 5);
  
  graph.insert(e0);
  graph.insert(e1);
  graph.insert(e2);
  graph.insert(e3);
  graph.insert(e4);
  graph.insert(e5);
  
  sPATH<AdjListGraph> s(graph, 0, 5);
  if(s.exists())
    std::cout << "connection has been found" << std::endl;
  if(s.existsHamil())
    std::cout << "a hamilton path exists" << std::endl;
}
