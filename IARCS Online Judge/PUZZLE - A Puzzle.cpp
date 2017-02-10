/*
  Author    : Aadesh Salecha
  Site      : IARCS.org
  Created   : Febuary 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;
const int MAX = 10;
vector< vector<int> > arr1, arr2, cpy;
int N;

void StepUp(int col)
{
	int tmp = cpy[0][col];
	for(int i = 0; i < N-1; i++)
		cpy[i][col] = cpy[i+1][col];
	cpy[N-1][col] = tmp;
}

void StepDown(int col)
{
	int tmp = cpy[N-1][col];
	for(int i = N-1; i > 0; i--)
		cpy[i][col] = cpy[i-1][col];
	cpy[0][col] = tmp;
}

int checkRow(int row)
{
	int ans = -1;
	vector<int> tmp;
	for(int i = 0; i < N; i++)
	{
		tmp = cpy[row];
		rotate(tmp.begin(), tmp.begin()+i, tmp.end());

		if(tmp == arr2[row])
			return i;
	}
	return ans;
}

bool canConvert(void)
{
	bool result = true;
	for(int i = 0; i < N; i++)
		if(checkRow(i) == -1)
		{
			// cout << "Row not " << i << " " << checkRow(i) << endl;
			result = false; break;
		}
	return result;
}

void printAns(int col, int c)
{
	cout << "YES\n" << c * (col+1) << " ";
	cpy = arr1;
	if(c == +1) StepUp(col);
	else StepDown(col);

	for(int i = 0; i < N; i++)
	{
		int tmp = checkRow(i);
		if(tmp != 0)
		{
			tmp = N - tmp;
			for(int k = 0; k < tmp; k++)
				cout << i+1 << " ";
		}
	}
	cout << endl;
}

int main(void)
{
	cin >> N;

	arr1.resize(N); arr2.resize(N);
	for(int i = 0; i < N; i++)
	{
		arr1[i].resize(N);
		for(int j = 0; j < N; j++)
			cin >> arr1[i][j];
	}

	for(int i = 0; i < N; i++)
	{
		arr2[i].resize(N);
		for(int j = 0; j < N; j++)
			cin >> arr2[i][j];
	}

	// loop over all columns
	for(int col = N-1; col >= 0; col--)
	{
		// do +1
		cpy = arr1; StepUp(col);		

		// for every row, check if it is proper
		if(canConvert())
		{
			printAns(col, +1);
			return 0;
		}

		// do -1
		cpy = arr1; StepDown(col);

		// for every row, check if it is proper
		if(canConvert())
		{
			printAns(col, -1);
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}