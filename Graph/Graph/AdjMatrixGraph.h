#pragma once
#include"Edge.h"
#include<vector>

/**
	Adjacency matrix representation of a graph.
	This representation is particularly suited to 
*/

class AdjMatrixGraph
{
	int vertexCount;
	int edgeCount;
	bool digraph;
	std::vector<std::vector<bool>> adj;
public:
	AdjMatrixGraph(int V, bool digraph = false) : adj(V), vertexCount(V), edgeCount(0) {
		for (auto v : adj) {
			v.assign(V, false); // this takes time proportional to vertexCount * vertexCount
		}
	}
	int V() const {
		return vertexCount;
	}
	int E() const {
		return edgeCount;
	}
	bool directed() const { return digraph; }
	void insert(Edge e){
		int v = e.v, w = e.w;
		if (adj[v][w] == false) {
			edgeCount++;
			adj[v][w] = true;
		}
		if (!digraph) adj[w][v] = true;
	}
	void remove(Edge e){
		int v = e.v, w = e.w;
		if (adj[v][w] == true) {
			edgeCount--;
			adj[v][w] = false;
		}
		if (!digraph) adj[w][v] = false;
	}
	bool edge(int v, int w) const{
		return adj[v][w];
	}
	class adjIterator;
	friend class adjIterator;
};

class AdjMatrixGraph::adjIterator
{
	const AdjMatrixGraph& G;
	int i;
	int v;
public:
	adjIterator(const AdjMatrixGraph &G, int v) :G(G), v(v), i(-1) {}
	int begin(){
		i = -1; return next();
	}
	int next() {
		for (i++; i < G.V(); i++)
			if (G.adj[v][i] == true) return i; // runs though the row of the matrix
		return -1;
	}
	bool end() {
		return i >= G.V();
	}
};