#pragma once
#include<vector>
template<class Graph>
class sPATH
{
	const Graph& G;
	std::vector<bool> visited;
	bool found;
	bool searchR(int v, int w)
	{
		if (v == w) return true;
		visited[v] = true;
		typename Graph::adjIterator A(G, v); // why typename before?
		
	}
};