/*
  Author    : Aadesh Salecha
  Site      : IARCS.org
  Created   : Febuary 2017
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 10000000
const int MAX = 3000 + 8;
vector<int> adj_list[MAX];
int pre_pos = 1, post[MAX], pre[MAX], D[MAX], volume[MAX];
bool visited[MAX];

void DFS(int source)
{
	if(visited[source]) return;
	visited[source] = true;

	pre[source] = pre_pos++;
	D[source] = volume[source];
	//cout << source << "  set to " << D[source] << endl;
	for(int i = 0; i < adj_list[source].size(); i++)
	{
		int v = adj_list[source][i];
		if(!visited[v])
        {
            DFS(v);
            D[source] += D[v];
        }
	}
	post[source] = pre_pos++;
}

bool isDes(int i, int j)
{
	if(pre[i] > pre[j] and post[i] < post[j])
		return true;
	return false;
}

int main(void)
{
	// freopen("inputf.in", "r", stdin);
	int N, a, b, c, x, y, max_of_three, result = INF;
	cin >> N;

	for(int i = 1; i <= N; i++)
    {
        cin >> volume[i];
        visited[i] = false;
    }

	for(int i = 0; i < N-1; i++)
	{
		cin >> x >> y;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}

	DFS(1);

    // for(int i = 1; i <= N; i++)
    //     cout << D[i] << " ";
    // cout << endl;

	for(int i = 1; i <= N; i++)
		for(int j = i+1; j <= N; j++)
		{
			// split at node i and j
			// is node i a descendant of j
			if(isDes(i, j))
			{
				a = D[1] - D[j];
				b = D[j] - D[i];
				c = D[i];
			}
			else if(isDes(j, i)) // is node j a descendant of i
			{
				a = D[1] - D[i];
				b = D[i] - D[j];
				c = D[j];
			}
			else // else they are siblings
			{
				a = D[1] - D[i] - D[j];
				b = D[i];
				c = D[j];
			}
			max_of_three = max(a, max(b, c));
			result = min(result, max_of_three);
		}
	cout << result << "\n";
}
