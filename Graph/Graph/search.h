#include<vector>
#include<iostream>
template<class Graph>
class sPATH
{
private:
  const Graph& G;
  std::vector<bool> visited;
  bool found, foundHamil;
  
  // Recursive search
  bool searchR(int v, int w){
    if (v == w) return true;
    visited[v] = true;
    // depth first search
    typename Graph::adjIterator A(G, v);
    for (int t = A.begin(); !A.end(); t = A.next()) {
      if (!visited[t]) {
	if (searchR(t, w)){
	  std::cout << t << " - " << v << std::endl;
	  return true;
	}
      }
    }
    return false;
  }

  // Hamilton path search
  bool searchR(int v, int w, int d){
    if(v == w) return (d == 0);
    visited[v] = true;
    typename Graph::adjIterator A(G, v);
    for(int t = A.begin(); !A.end(); t = A.next()){
      if( !visited[t] ){
	if( searchR(t, w, d-1) ){
          std::cout << t << " - " << v << std::endl;
	  return true;
	}
      }
    }
    visited[v] = false;
    return false;
  }
  
public:
  sPATH(const Graph&G, int v, int w) :G(G), visited(G.V(), false){
    // we are interested in the path from v to w,
    // but due to the recursive nature of the
    // algorithm we need to switch w and v to get
    // correct printing results. From undirec. graphs
    // at least
    found      =    searchR(w, v);
    visited.assign(G.V(), false);
    foundHamil =    searchR(w, v, G.V()-1);
  }
  bool exists() const{
    return found;
  }
  bool existsHamil() const{
    return foundHamil;
  }
};
