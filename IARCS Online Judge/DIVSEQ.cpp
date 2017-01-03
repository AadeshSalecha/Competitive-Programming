#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
int const MAX = 10000+7;
int data[MAX], DP[MAX];

int main(void)
{
	int N; cin >> N;

	for(int i = 0; i < N; i++)
		cin >> data[i];

	memset(DP, 0, sizeof(DP[0]) * N);
	int result = 0;
	for(int i = 0; i < N; i++)
	{
		int best = 0;
		for(int j = 0; j < i; j++)
			if(data[i] % data[j] == 0)
				if(DP[j] > best)
					best = DP[j];
		DP[i] += 1 + best;
		result = max(result, DP[i]);
	}
	cout << result << "\n";
	return 0;
}
