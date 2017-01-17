/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MARK -10000000
using namespace std;

const long long MAX = 700 + 7;
long long values[MAX], brackets[MAX], memo[MAX][MAX], N, K;

bool doesMatch(long long i, long long j)
{
    return (K + brackets[i] == brackets[j]);
}

long long maxValue(long long i, long long j)
{
    if(i >= j) return 0;
    if(memo[i][j] != MARK) return memo[i][j];

    long long ans = 0;
    for(int k = i+1; k <= j; k++)
        if(doesMatch(i, k))
            ans = max(ans, values[i] + values[k] + maxValue(i+1, k-1) + maxValue(k+1, j));

    ans = max(ans, maxValue(i+1, j-1)); // Don't use these 2 brackets
    ans = max(ans, maxValue(i+1, j));
    ans = max(ans, maxValue(i, j-1));

    return memo[i][j] = ans;
}

int main(void)
{
    cin >> N >> K;

    for(long long i = 0; i < N; i++)
        cin >> values[i];
    for(long long i = 0; i < N; i++)
        cin >> brackets[i];

    for(long long i = 0; i < N; i++)
        for(long long j = 0; j < N; j++)
            memo[i][j] = MARK;

    cout << max(0LL, maxValue(0, N-1)) << "\n";
}
