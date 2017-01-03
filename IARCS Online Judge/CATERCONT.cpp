#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
const int MAX = 100000 + 7;
int memo[MAX];
int volume[MAX];
vector< vector<int> > adj_list;

int f(int u, int direct)
{
	if(memo[u] != -1) return memo[u];

	// if i am selected
	int selected = volume[u], v;
	for(int i = 0; i < adj_list[u].size(); i++)
	{
		v = adj_list[u][i];
		if(v != direct)
		{
			for(int j = 0; j < adj_list[v].size(); j++)
				if(adj_list[v][j] != u and adj_list[v][j] != direct)
					selected += f(adj_list[v][j], v);
		}
	}

	// if i'm not selected
	int not_selected = 0;
	for(int i = 0; i < adj_list[u].size(); i++)
	{
		v = adj_list[u][i];
		if(v != direct)
			not_selected += f(v, u);
	}

	return memo[u] = max(selected, not_selected);
}

int main(void)
{
	int V, E, u, v;
	cin >> V;

	adj_list.resize(V+1); 
	memset(memo, -1, sizeof(memo));

	for(int i = 1; i < V+1; i++)
		cin >> volume[i];

	for(int i = 0; i < V-1; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);		
	}

	cout << f(1, -1) << "\n";
	return 0;
}

