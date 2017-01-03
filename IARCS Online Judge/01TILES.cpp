#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

int main(void)
{
	long long n; cin >> n;
	const int mod = 15746;
	int cur = 1, prev = 1, sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		sum = (cur + prev) % mod;
		prev = cur;
		cur = sum;
	}
	cout << sum % mod << endl;
	return 0;
}