#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
vector< vector<int> > adj_list;
vector<bool> articulation_points;
vector<int> dfs_num; vector<int> dfs_low;
int dfsTime = 1, rootChildren, dfsRoot;

void DFS(int u, int direct_parent)
{
	if(dfs_num[u] != -1) return;
	dfs_num[u] = dfs_low[u] = dfsTime++;
	for(int i = 0; i < adj_list[u].size(); i++)
	{
		int v = adj_list[u][i];
		if(dfs_num[v] == -1)
		{
			if(u == dfsRoot) rootChildren++;
			DFS(v, u);

			if(dfs_low[v] >= dfs_num[u])
				articulation_points[u] = true;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != direct_parent)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

void ArticulationPoints(int V, int E)
{
	// set dfs num and lows
	dfs_num.assign(V+1, -1); dfs_low.assign(V+1, -1);
	articulation_points.assign(V+1, false);

	// call with dfs(0) 
	dfsRoot = 1, rootChildren = 0, dfsTime = 1;
	DFS(1, -1);

	// check if root is articulation point
	articulation_points[dfsRoot] = (rootChildren > 1);
}

int main(void)
{
	int V, E, u, v;
	cin >> V >> E;

	adj_list.resize(V+1);
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}	

	ArticulationPoints(V, E);

	cout << count(articulation_points.begin(), articulation_points.end(), true) << "\n";
	for(int i = 1; i < V+1; i++)
		if(articulation_points[i])
			cout << i << "\n";
	return 0;
}