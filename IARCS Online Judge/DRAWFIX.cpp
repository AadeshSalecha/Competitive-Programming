#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

struct Player
{
	int index, val;
};

bool cmp(Player a, Player b)
{
	return a.val < b.val;
}

const int MAX = 50000+7;
Player a[MAX], b[MAX];
int result[MAX];

int main(void)
{
	int N, tmp;
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		cin >> tmp;
		a[i].index = i; a[i].val = tmp;
	}

	for(int i = 1; i <= N; i++)
	{
		cin >> tmp;
		b[i].index = i; b[i].val = tmp;
	}

	sort(a+1, a+N+1, cmp); sort(b+1, b+N+1, cmp);

	int a_l = 1, a_r = N, b_l = 1, b_r = N, win = 0;
	Player my, their;
	for(int i = 1; i <= N; i++)
	{
		if(a[a_l].val < b[b_l].val)
		{
			// put my player with their strongest player
			my = a[a_l], their = b[b_r];
			a_l++, b_r--;
		}
		else
		{
			// we win this match
			win++;
			my = a[a_l], their = b[b_l];
			a_l++, b_l++;
		}
		result[my.index] = their.index;
	}
	
	cout << win << "\n";
	for(int i = 1; i <= N; i++)
		cout << result[i] << "\n";

	return 0;
}