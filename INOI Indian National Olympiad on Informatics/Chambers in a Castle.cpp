/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

const int MAX = 500+7;
int grid[MAX][MAX];
int dr[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dc[] = {-1, -1, -1, 0, 1, 1, 1, 0};

int FloodFill(int i, int j, int cc, int N, int M)
{
	if(grid[i][j] != 0) return 0;
	if(j < 0 or j >= M or i < 0 or i >= N) return 0;

	grid[i][j] = cc;
	int ans = 0;
	for(int z = 0; z < 8; z++)
		ans += FloodFill(i + dr[z], j + dc[z], cc, N, M);
	return 1 + ans;
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	memset(grid, -10, sizeof(grid));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> grid[i][j];

	int numComponents = 10, best = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(grid[i][j] == 0)
				best = max(best, FloodFill(i, j, numComponents++, N, M));				

	printf("%i\n%i\n", numComponents-10, best);
	return 0;
}

