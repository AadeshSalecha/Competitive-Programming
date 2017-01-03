#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

const int MAX = 10000+7;
int a[MAX];

int main(void)
{
	int N; cin >> N;

	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a+N);

	int avg = 0;
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
		{
			int tmp = (a[i] + a[j]) / 2;
			if((a[i] + a[j]) % 2 == 0)
				if(binary_search(a+i, a+N, tmp))
				{
					// cout << i << " " << j << " " << a[i] + a[j];
					// cout << " " << upper_bound(a+i, a+N, tmp) - lower_bound(a+i, a+N, tmp) << "\n";
					avg += 1; // upper_bound(a+i, a+N, tmp) - lower_bound(a+i, a+N, tmp);
				}
		}
	cout << avg << "\n";
	return 0;
}