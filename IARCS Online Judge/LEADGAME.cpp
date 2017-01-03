#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

int main(void)
{
	int best = 0, winner, N, first, second, lead, a = 0, b = 0; cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> first >> second;
		a += first;
		b += second;
		lead = abs(a - b);
		if(lead > best)
		{
			best = lead;
			winner = (a > b)? 1 : 2;
		}
	}
	cout << winner << " " << best << "\n";
	return 0;
}
