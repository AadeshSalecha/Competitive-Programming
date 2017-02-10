/*
  Author    : Aadesh Salecha
  Site      : IARCS.org
  Created   : Febuary 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstring>
#define INF 100000
#define mp make_pair
using namespace std;
const int MAX = 160;
int books[MAX], N;
map< pair<int, int>, int> memo;

int Knapsack(int i, int weight)
{
    if(weight == 0 or i < 0 or i >= N) return 0;
    if(weight < 0) return -INF;

    if(memo.find(mp(i, weight)) != memo.end())
        return memo[mp(i, weight)];

    int a = Knapsack(i+1, weight);
    if(books[i] <= weight)
        a = max(a, Knapsack(i+1, weight - books[i]) + books[i]);
    return memo[mp(i, weight)] = a;  
}

int main(void)
{
    int a, b, sum = 0; cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a >> b;
        books[i] = abs(a-b);
        sum += abs(a-b);
    }

    cout << sum - (2 *Knapsack(0, sum / 2)) << endl;
    return 0;
}