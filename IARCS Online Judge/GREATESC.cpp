#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
#define INF 100000

vector< vector<int> > adj_list;

int BFS(int source, int target, int V, int E)
{
	vector<int> dist(V+1, INF);
	dist[source] = 0;

	queue<int> bfs;
	bfs.push(source);

	int cur, v;
	while(bfs.empty() != true and cur != target)
	{
		cur = bfs.front(); bfs.pop();

		for(int i = 0; i < adj_list[cur].size(); i++)
		{
			v = adj_list[cur][i];
			if(dist[v] == INF)
				dist[v] = dist[cur] + 1, bfs.push(v);
		}
	}

	// for(int i = 1;i < V+1; i++)
	// 	cout << dist[i] << " ";
	// cout << "\n";

	if(dist[target] == INF)
		return 0;
	return dist[target];
}

int main(void)
{
	int V, E, u, v, target, source;
	cin >> V >> E;

	adj_list.resize(V+1);
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}	

	cin >> source >> target;
	cout << BFS(source, target, V, E) << "\n";
	return 0;
}
