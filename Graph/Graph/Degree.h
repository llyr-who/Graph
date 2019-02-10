#include<vector>
template<typename Graph>
class Degree
{
private:
  const Graph &G;
  std::vector<int> degree;
public:
  Degree(const Graph &G) : G(G), degree(G.V(), 0)
  {
    for(int v = 0; v < G.V(); v++){
      typename Graph::adjIterator A(G, v);
      for( int w = A.begin(); !A.end(); w = A.next()){
	degree[v]++;
      }
    }
  }
  int operator[](int v) const
  {
    return degree[v];
  }
};
