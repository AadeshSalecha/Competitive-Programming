#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 1000 + 7;
int in[MAX];
bool visited[MAX];

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, start, cur;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> in[i];

    vector<int> cur_cycle;
    vector< vector<int> > all_cycles;

    memset(visited, false, sizeof(visited[0]) * (N + 1));

    for(int i = 1; i <= N; i++)
        if(!visited[i])
        {
            start = i;
            cur = in[start];
            cur_cycle.clear(); cur_cycle.push_back(start);

            // walk through the cycle
            while(cur != start)
            {
                visited[cur] = true;
                cur_cycle.push_back(cur);
                cur = in[cur];
            }

            // store cycle
            cur_cycle.push_back(start);
            all_cycles.push_back(cur_cycle);
        }

    cout << all_cycles.size() << "\n";
    for(int i = 0; i < all_cycles.size(); i++)
    {
        for(int j = 0; j < all_cycles[i].size(); j++)
            cout << all_cycles[i][j] << " ";
        cout << endl;
    }
}
