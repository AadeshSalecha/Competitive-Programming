#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
#define INF 10000

const int MAX = 3000 + 7;
vector<int> adj_list[MAX];
int hate[MAX];
bool removed[MAX];

int main(void)
{
    // freopen("inputf.in", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int V, E, K, u, v, cur;
    scanf("%i %i %i", &V, &E, &K);

    for(int i = 0; i < E; i++)
    {
        scanf("%i %i", &u, &v);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    queue<int> remove_these;
    for(int i = 1; i < V+1; i++)
    {
        hate[i] = adj_list[i].size();
        if(adj_list[i].size() < K) // remove this guy
            remove_these.push(i);
    }

    int ans = V;
    memset(removed, false, sizeof(removed[0]) * (V+1));
    while(remove_these.empty() == false)
    {
        cur = remove_these.front(); remove_these.pop();
        if(removed[cur]) continue;
        removed[cur] = true;

        ans--;

        for(int i = 0; i < adj_list[cur].size(); i++)
        {
            v = adj_list[cur][i];
            if(!removed[v])
            {
                hate[v]--;
                if(hate[v] < K)
                    remove_these.push(v);
            }
        }
    }

    if(ans > 0)
        printf("YES\n%i\n", ans);
    else
        printf("NO\n");
}
