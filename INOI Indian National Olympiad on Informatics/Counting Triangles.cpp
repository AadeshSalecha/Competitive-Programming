/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define MARK -10000000
#define mp make_pair

using namespace std;
const int MAX = 1000000 + 7;
const int MOD = 10000;
pair<long long, long long> points[MAX];

int main(void)
{
    long long x, y, tmp, N; cin >> N;

    map<long long, long long> x_points, y_points;

    for(long long i = 0; i < N; i++)
    {
        cin >> x >> y;
        if(x_points.find(x) == x_points.end())
            x_points[x] = 1;
        else
            x_points[x]++;

        if(y_points.find(y) == y_points.end())
            y_points[y] = 1;
        else
            y_points[y]++;

        points[i] = mp(x, y);
    }

    long long right = 0;
    for(int i = 0; i < N; i++)
    {
        x = points[i].first, y = points[i].second;
        tmp = (x_points[x]-1) * (y_points[y]-1);
        right = (tmp + right) % MOD;
    }
    cout << right % MOD << "\n";
}