#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

const long long MAX = 999999999;
bool seen[10];

bool isRepFree(long long i)
{
	if(i == 0) return false;

	memset(seen, false, sizeof(seen));
	while(i)
	{
		// digit is i % 10
		if(i % 10 == 0 or seen[i % 10]) return false;
		seen[i % 10] = true;

		i /= 10;
	}
	// for(int i = 0; i < 10; i++)
	// 	cout << seen[i] << " ";
	// cout << endl;

	return true;
}

int main(void)
{
	int N; cin >> N;
	bool ans = false;
	for(int i = N + 1; i <= MAX; i++)
	{
		if(isRepFree(i))
		{
			ans = true;
			cout << i << "\n";
			break;
		}
	}
	if(!ans)
		cout << "0\n";
	// for(int i = 0; i <= 100; i++)
	// 	cout << i << " " << isRepFree(i) << endl;

	return 0;
}