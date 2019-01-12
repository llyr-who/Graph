#pragma once
#include<vector>
#include<iostream>
template<class Graph>
class sPATH
{
	const Graph& G;
	std::vector<bool> visited;
	bool found;
	bool searchR(int v, int w){
		if (v == w) return true;
		visited[v] = true;
		// depth first search
		typename Graph::adjIterator A(G, v);
		for (int t = A.begin(); !A.end(); t = A.next()) {
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