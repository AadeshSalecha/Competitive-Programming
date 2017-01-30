/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <numeric>
using namespace std;

struct Edge
{
	int u, v, w;
};

int V, E;
vector< vector<Edge> > adj_list;
vector<Edge> edge_list;

void BellmanFord(int source, vector<int> dist[])
{
	int v, u , w;
	// bellman ford
	dist[source][source] = 0;
	for(int i = 0; i < V; i++)
		for(int u = 1; u < V+1; u++)
			for(int _v = 0; _v < adj_list[u].size(); _v++)
			{
				u = adj_list[u][_v].u;	
				v = adj_list[u][_v].v;
				w = adj_list[u][_v].w;
				if(dist[source][u] != INT_MAX and dist[source][v] > dist[source][u] + w)
					dist[source][v] = dist[source][u] + w;
			}
}

void Dijkstra(int source, vector<int> dist[])
{
	dist[source][source] = 0;

	priority_queue< pair<int, int> > tmp;
	tmp.push(make_pair(0, source));

	int cur, cur_dist, u, v, w;
	while(tmp.empty() != true)
	{
		cur = tmp.top().second; cur_dist = tmp.top().first; tmp.pop();
		
		if(dist[source][cur] < cur_dist) continue;

		for(int i = 0; i < adj_list[cur].size(); i++)
		{
			u = adj_list[cur][i].u;
			v = adj_list[cur][i].v;
			w = adj_list[cur][i].w;

			if(dist[source][u] != INT_MAX and dist[source][v] > dist[source][u] + w)
			{
				dist[source][v] = dist[source][u] + w;
				tmp.push(make_pair(dist[source][v], v));
			}
		}
	}
}

void FloydWarshall(vector<int> dist[])
{
	for(int i = 1; i < V+1; i++)
		for(int j = 0; j < adj_list[i].size(); j++)
			dist[i][adj_list[i][j].v] = adj_list[i][j].w;

	for(int i = 1; i < V+1; i++)
		dist[i][i] = 0;	

	for(int k = 1; k < V+1; k++)
		for(int i = 1; i < V+1; i++)
			for(int j = 1; j < V+1; j++)
				if((dist[i][k] != INT_MAX and dist[k][j] != INT_MAX) and dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

void maximizeCheapest(void)
{
	vector<int> dist[V+1];
	for(int i = 0; i < V+1; i++)
		for(int j = 0; j < V+1; j++)
			dist[i].push_back(INT_MAX);
	
	// Approach 1: bellman ford v times - TLEs on 2nd and 3rd subtask
	// for(int source = 1; source < V+1; source++)
	// 	BellmanFord(source, dist);

	// Approach 2: run Dijkstra v time
	// for(int source = 1; source < V+1; source++)
	// 	Dijkstra(source, dist);

	// Approach 3: run flyod warshall
	FloydWarshall(dist);

	// output maximum cheapest
	int maximum = -INT_MAX, e, f;
	for(int i = 1; i < V+1; i++)
		for(int j = i+1; j < V+1; j++)
			if(dist[i][j] > maximum)
				maximum = dist[i][j], f = i, e = j;
	cout << maximum << endl;
}

int main(void)
{
	Edge tmp;
	cin >> V >> E;

	adj_list.resize(V+1);
	for(int i = 0; i < E; i++)
	{
		cin >> tmp.u >> tmp.v >> tmp.w;
		adj_list[tmp.u].push_back(tmp);
		swap(tmp.u, tmp.v);
		adj_list[tmp.u].push_back(tmp);				
	}

	maximizeCheapest();
	return 0;
}