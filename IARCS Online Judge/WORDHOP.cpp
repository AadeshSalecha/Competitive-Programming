#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define INF 10000

const int MAX = 100 + 7;
string strings[MAX];
int DP[MAX], edit_distance[13][13], match, del, rep;
map<char, int> index_in_a;
vector< vector<int> > adj_list;

bool canHop(string a, string b)
{
    if(abs((int)a.size() - (int)b.size()) > 1) return false;

    for(int i = 0; i <= a.size(); i++)
        edit_distance[i][0] = i;

    for(int i = 0; i <= b.size(); i++)
        edit_distance[0][i] = INF;

    edit_distance[0][0] = 0;

    index_in_a.clear();
    for(int i = 0; i < a.size(); i++)
        index_in_a[a[i]] = i;

    for(int i = 1; i <= a.size(); i++)
        for(int j = 1; j <= b.size(); j++)
        {
            if((a[i-1] == b[j-1])) // match
                match = edit_distance[i-1][j-1];
            else
                match = INF;

            if(b[j-1] > a[i-1] and index_in_a[b[j-1]] > i - 1) // replace a[i] with b[j]
                rep = 1 + edit_distance[i-1][j-1];
            else
                rep = INF;

            // delete
            del = 1 + edit_distance[i-1][j];

            edit_distance[i][j] = min(match, min(rep, del));
        }
    return (edit_distance[(int)a.size()][(int)b.size()] <= 1);
}

int maxDFS(int u, int V, int visited[])
{
    if(visited[u] != 0) return visited[u];
    visited[u] = 1;

    int maximum_depth = 0;
    for(int i = 0; i < adj_list[u].size(); i++)
        maximum_depth = max(maximum_depth, maxDFS(adj_list[u][i], V, visited));

    return visited[u] = 1 + maximum_depth;
}

int main(void)
{
    // freopen("inputf.in", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int N; cin >> N;

    for(int i = 0; i < N; i++)
        cin >> strings[i];

    adj_list.resize(N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(canHop(strings[i], strings[j]) and i != j)
                adj_list[i].push_back(j);

    int visited[N]; memset(visited, false, sizeof(visited));

    int result = 0;
    for(int i = 0; i < N; i++)
        if(!visited[i])
            result = max(result, maxDFS(i, N, visited));
    cout << result << endl;
}
