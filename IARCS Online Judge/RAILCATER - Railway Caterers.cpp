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
const int MAX = 1000000  + 8;
int station[MAX], DP[MAX], prefix[MAX];

int main(void)
{
//	 freopen("inputf.in", "r", stdin);
	int N, K;
	cin >> N >> K;

    prefix[0] = 0;
	for(int i = 1; i <= N; i++)
    {
        cin >> station[i];
        prefix[i] = prefix[i-1] + station[i];
    }

	DP[K] = prefix[K];

	int result = -INF;
	for(int i = K+1; i <= N; i++)
	{
		DP[i] = max(DP[i-1] + station[i], prefix[i] - prefix[i-K]);
		result = max(result, DP[i]);
	}
	cout << max(prefix[N], result) << endl;
}
