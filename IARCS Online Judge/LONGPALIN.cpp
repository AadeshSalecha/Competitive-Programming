#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

bool DP[5000+7][2];


void longestPalindrome(string a)
{
	memset(DP, true, sizeof(DP[0])*a.size());

	int best_l = 0, best_r = 0;
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			DP[j][1] = (a[j] == a[i] and DP[j+1][0]);
			if(DP[j][1] and i - j > best_r - best_l)
				best_l = j, best_r = i;
		}	
		for(int z = 0; z < i; z++)
			DP[z][0] = DP[z][1];

		// // cout << i << endl;
		// for(int z = 0; z < i+1; z++)
		// 	cout << DP[z][0] << " ";
		// cout << endl; // << endl;
	}

	// for(int i = 0; i < a.size(); i++)
	// {
	// 	for(int j = 0; j < i+1; j++)
	// 		cout << DP[i][j] << " ";
	// 	cout << endl;
	// }

	cout << best_r - best_l + 1 << "\n";
	for(int i = best_l; i <= best_r; i++)
		cout << a[i];
	cout << "\n";
}

int main(void)
{
	int n; cin >> n;
	string a; cin >> a;

	longestPalindrome(a);	
	return 0;
}