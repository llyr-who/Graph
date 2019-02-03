#include<vector>
#include<iostream>
template<class Graph>
class sPATH
{
private:
  const Graph& G;
  std::vector<bool> visited;
  bool found;
  bool searchR(int v, int w){
    if (v == w) return true;
    visited[v] = true;
    // depth first search
    typename Graph::adjIterator A(G, v);
    for (int t = A.begin(); !A.end(); t = A.next()) {
      
      // for debugging we are going to print the contents
      typename Graph::adjIterator B(G,v);
      std::cout << "debug" << std::endl;
      for(int s = B.begin(); !B.end(); s = B.next()){
	std::cout << v << " is connected to " << s << std::endl;
      }
      
      
      if (!visited[t]) {
	if (searchR(t, w)){ 
	  return true;
	}
	return false;
      }
    }
  }
public:
  sPATH(const Graph&G, int v, int w) :G(G), visited(G.V(), false){
    found = searchR(v, w);
  }
  bool exists() const{
    return found;
  }
};
