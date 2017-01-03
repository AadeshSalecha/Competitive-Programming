#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define INF 10000
const int MAX = 100000;
pair<long long, long long> events[MAX];

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> events[i].first >> events[i].second;
        events[i].second += events[i].first;
    }

    sort(events, events + N, cmp);
    long long ans = 0, cur = 0;
    for(int i = 0; i < N; i++)
    {
        if(events[i].first > cur)
            ans++, cur = events[i].second;
    }
    cout << ans << endl;
}
