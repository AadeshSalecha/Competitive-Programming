#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define INF 100000
const int MAX = 2000 + 7;

int parent[MAX], size[MAX];
bool vis[MAX][MAX];
pair<int, pair<int, int> > edge_list[2000 * 2000 + 7];

struct UnionFind
{
    void MakeUnionFind(int V)
    {
        for(int i = 1; i < V+1; i++)
            parent[i] = i, size[i] = 1;
    }
    int Find(int a)
    {
        return (parent[a] == a) ? a : parent[a] = Find(parent[a]);
    }
    void Union(int a, int b)
    {
        int r1 = Find(a), r2 = Find(b);
        if(r1 == r2) return;
        if(size[r1] > size[r2])
            swap(r1, r2);

        size[r2] += size[r1];
        parent[r1] = parent[r2];
    }
};

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
{
    return a.second.second < b.second.second;
}

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int V, v, u, w, edges = 0, ans = 0, count = 0; 
    pair<int, pair<int, int> > tmp;
    scanf("%i", &V);

    for(int u = 1; u <= V; u++)
    {
        tmp.first = u;
        for(int v = 1; v <= V; v++)
        {
            tmp.second.first = v;
            scanf("%i", &tmp.second.second);
            if(u != 1 and v != 1 and !vis[u][v])
                edge_list[count++] = tmp, vis[u][v] = vis[v][u] = true;
        }
    }

    sort(edge_list, edge_list + count, cmp);

    // Kruskal
    UnionFind uf; uf.MakeUnionFind(V+1);

    for(int i = 0; i < count and edges != V-1; i++)
    {
        u = edge_list[i].first, v = edge_list[i].second.first, w = edge_list[i].second.second;
        if(uf.Find(u) != uf.Find(v))
        {
            uf.Union(u, v);
            edges++; ans += w;
        }
    }
    cout << ans << "\n";
}
