#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 10000

const int MAX = 2000 + 7;
vector<int> adj_list[MAX];
int visited[MAX], bestChild[MAX], memo[MAX];

int maxDFS(int source)
{
    // begin processed (back edge to ancestor)
    if(visited[source] == -1) return 0;

    // finished processing (forward / cross edge)
    if(visited[source] == 1) return memo[source];

    // set visited to being processed
    visited[source] = -1;

    int maximum = -1, v, tmp;
    for(int i = 0; i < adj_list[source].size(); i++)
    {
        v = adj_list[source][i];
        if(visited[v] == 0) // vertex hasn't been processed yet
        {
            tmp = maxDFS(v);
            if(maximum == -1 or tmp > maximum)
                maximum = tmp, bestChild[source] = v;
        }
    }

    visited[source] = 1;
    if(maximum == -1) // this is the last vertex in the path
    {
        bestChild[source] = -1; return memo[source] = 1;
    }
    return memo[source] = 1 + maximum;
}

void printDFS(int source)
{
    int cur = source;
    while(bestChild[cur] != -1)
    {
        cout << cur << " ";
        cur = bestChild[cur];
    }
    cout << cur << endl;
}

int main(void)
{
    int v, num, V;
    bool ans = false;

    cin >> V;
    for(int i = 1; i < V+1; i++)
    {
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> v;
            adj_list[i].push_back(v);
        }
    }

    // This part basically runs DFS from the ith nodes and checks
    // if all the nodes can be reached from this node, while 
    // satisfying the constraint (ie. each minister defeats the next)
    for(int i = 1; i <= V; i++)
    {
        memset(visited, 0, sizeof(visited[0]) * (V+1));
        if(maxDFS(i) == V) // the solution starts with the ith vertex
        {
            ans = true;
            cout << "YES\n";
            printDFS(i); break;
        }
    }

    if(!ans)
        cout << "NO\n";
}
