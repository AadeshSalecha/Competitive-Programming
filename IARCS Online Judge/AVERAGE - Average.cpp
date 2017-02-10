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
const int MAX = 10000 + 8;
int nums[MAX], N;

bool isAverage(int t)
{
	int i = 0, j = N-1;
	while(i < j)
	{
		if((nums[i] + nums[j]) % 2 == 0 and (nums[i] + nums[j]) / 2 == t)
            return true;
		else if((nums[i] + nums[j]) / 2 > t)
			j--;
		else
			i++;
	}
	return false;
}

int main(void)
{
//	 freopen("inputf.in", "r", stdin);
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums, nums + N);

	int count = 0;
	for(int i = 0; i < N; i++)
		if(isAverage(nums[i]))
        {
            count++;
        }
	cout << count << endl;
}
