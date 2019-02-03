#include"Edge.h"
#include<vector>
class AdjListGraph
{
private:
  int vertexCount;
  int edgeCount;
  bool digraph;
  struct node
  {
    int v; node* next;
    node(int x, node*t) { v = x; next = t; }
  };
  typedef node* link;
  std::vector<link> adj;
public:
  AdjListGraph(int V, bool digraph = false) : adj(V),
					      vertexCount(V),
					      edgeCount(0),
					      digraph(digraph) {
    adj.assign(V, NULL);
  }
  int V() const { return vertexCount; }
  int E() const { return edgeCount;  }
  bool directed() const { return digraph; }
  void insert(Edge e){
    int v = e.v, w = e.w;
    adj[v] = new node(w, adj[v]);
    if (!digraph) adj[w] = new node(v, adj[w]);
    edgeCount++;
  }
  // this assumes that the edge exists
  void remove(Edge e){
    int v = e.v, w = e.w;
    link t = adj[v];
    if (t->v != w) {
      while (t->next->v != w) {
	t = t->next;
      }
    }
    if (t->next == NULL) {
      delete t;
    }
    else {
      link s = t->next;
      t->next = t->next->next;
      delete s;
    }
    if (!digraph){
	// if the graph is not directed then
	// we need to remove the other edge.
	t = adj[w];
      }
  }
  bool edge(int v, int w) const {
    link t = adj[v];
    if (t == NULL) return false;
    while (t->v != w){
      t = t->next;
      if (t == NULL)
	return false;
    }
    return true;
  }
  class adjIterator;
  friend class adjIterator;
};

class AdjListGraph::adjIterator {
  const AdjListGraph &G;
  int v;
  link t;
public:
  adjIterator(const AdjListGraph&G, int v) : G(G), v(v) { t = 0; }
  int begin() {
    t = G.adj[v];
    return t ? t->v : -1;
  }
  int next(){
    if (t) t = t->next;
    return t ? t->v : -1;
  }
  bool end(){
    return t == NULL;
  }
};
