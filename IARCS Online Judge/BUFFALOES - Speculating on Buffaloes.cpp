/*
  Author    : Aadesh Salecha
  Site      : IARCS.org
  Created   : Febuary 2017
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 10000000
const int MAX = 400 + 8;
int price[MAX], memo[MAX][MAX][2], N;

int maximise(int i, bool has, int K)
{
	if(i >= N or K < 1) return 0;
	if(memo[i][K][has] != -1) return memo[i][K][has];

	if(has)
	{
		// either sell
		int sell = maximise(i+1, false, K-1) + price[i];

		// or move on
		int move_on = maximise(i+1, true, K);
		return memo[i][K][has] = max(move_on, sell);
	}
	else
	{
		// either buy
		int buy = maximise(i+1, true, K-1) - price[i];

		// or move on
		int move_on = maximise(i+1, false, K);
		return memo[i][K][has] = max(move_on, buy);
	}
}

int main(void)
{
    // freopen("inputf.in", "r", stdin);
	int K;
	cin >> N >> K;

	for(int i = 0; i < N; i++)
		cin >> price[i];

    memset(memo, -1, sizeof(memo));
	cout << maximise(0, false, K) << endl;
}
