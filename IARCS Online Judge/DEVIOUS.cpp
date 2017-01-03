#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 100000
const int MAX = 100000;
pair<int, int> station[MAX];

int main(void)
{
//    freopen("inputf.in", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int N; cin >> N;

    station[0].first = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> station[i].first, station[i].first += station[i-1].first;
        station[i].second = i;
    }

    sort(station+1, station + N + 1);

    int best = INF, start = 0, stop = 0, tmp;
    pair<int, int> a, b;
    for(int i = 2; i <= N; i++)
    {
        if(station[i].second > station[i-1].second)
            a = station[i-1], b = station[i];
        else
            a = station[i], b = station[i-1];


        tmp = b.first - a.first;
        if(abs(tmp) < abs(best) or (abs(tmp) == abs(best) and stop - start < (b.second - (a.second + 1))))
            best = tmp, start = a.second + 1, stop = b.second;
    }
    cout << best << "\n" << start << " " << stop << "\n";
}
