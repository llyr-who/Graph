#pragma once
#include"Edge.h"
#include<vector>

/**
	Adjacency matrix representation of a multigraph.
	
	a multigraph is a graph that can have multiple
	parallel edges. this requires a slight modification
	to the adj. mat. rep. of a graph to keep track
	of a vec of vec of ints rather than bools
*/

class AdjMatrixMultiGraph
{
	int vertexCount;
	int edgeCount;
	bool digraph;
	std::vector<std::vector<int>> adj;
public:
	AdjMatrixMultiGraph(int V, bool digraph = false) : adj(V), vertexCount(V), edgeCount(0) {
		for (auto&& v : adj) {
			v.assign(V, 0); // this takes time proportional to vertexCount * vertexCount
		}
	}
	int V() const {
		return vertexCount;
	}
	int E() const {
		return edgeCount;
	}
	bool directed() const { return digraph; }
	void insert(Edge e) {
		int v = e.v, w = e.w;
		edgeCount++;
		adj[v][w]++;
		if (!digraph) adj[w][v]++;
	}
	// we should check whether the entry is 0 or not.
	void remove(Edge e) {
		int v = e.v, w = e.w;
		edgeCount--;
		adj[v][w]--;
		if (!digraph) adj[w][v]--;
	}
	bool edge(int v, int w) const {
		return adj[v][w];
	}
	class adjIterator;
	friend class adjIterator;
};

class AdjMatrixMultiGraph::adjIterator
{
	const AdjMatrixMultiGraph& G;
	int i;
	int v;
public:
	adjIterator(const AdjMatrixMultiGraph &G, int v) :G(G), v(v), i(-1) {}
	int begin() {
		i = -1; return next();
	}
	int next() {
		for (i++; i < G.V(); i++)
			if (G.adj[v][i]) return i; // runs though the row of the matrix
		return -1;
	}
	bool end() {
		return i >= G.V();
	}
};