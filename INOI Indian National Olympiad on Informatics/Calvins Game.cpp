/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
#define INF 100000000
const int MAX = 1000000 + 7;
int forward[MAX], backward[MAX], num[MAX];

int main(void)
{
	int N, start;
	cin >> N >> start;

	num[0] = num[1] = num[2] = num[3] = 0;
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];	
		forward[i] = backward[i] = 0;
	}

	forward[start] = 0; forward[start+1] = num[start+1];
	for(int i = start+2; i <= N; i++)
		forward[i] = max(forward[i-1], forward[i-2]) + num[i];
	
	backward[1] = 0; backward[2] = num[1];
	for(int i = 3; i <= N; i++)
		backward[i] = max(backward[i-1] + num[i-1], backward[i-2] + num[i-2]);

	int maximum = -INF;
	for(int i = start; i <= N; i++)
		maximum = max(forward[i] + backward[i], maximum);
	cout << maximum << endl;
	return 0;
}