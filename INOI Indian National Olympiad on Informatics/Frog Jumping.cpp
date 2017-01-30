/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000
#define R first
#define D second

const int MAX = 250 + 7;
pair<int, int> grid[MAX][MAX];
int DP[MAX][MAX];

int main(void)
{
    int N, M, right, bottom;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> grid[i][j].R;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> grid[i][j].D;

    DP[N][M] = 0;
    // initialize bottom row
    for(int i = M-1; i > 0; i--)
    {
        DP[N][i] = INF;
        for(int j = i+1; j <= min(M, i+grid[N][i].R); j++)
            DP[N][i] = min(DP[N][i], 1 + DP[N][j]);
    }

    // initialize last column
    for(int i = N-1; i > 0; i--)
    {
        DP[i][M] = INF;
        for(int j = i+1; j <= min(N, i+grid[i][M].D); j++)
            DP[i][M] = min(DP[i][M], 1 + DP[j][M]);
    }

    // Bottom up DP
    for(int i = N-1; i > 0; i--)
        for(int j = M-1; j > 0; j--)
        {
            right = bottom = INF;
            // best possible right
            for(int z = j+1; z <= min(M, grid[i][j].R + j); z++)
                right = min(right, 1 + DP[i][z]);

            // best possible down
            for(int z = i+1; z <= min(N, grid[i][j].D + i); z++)
                bottom = min(bottom, 1 + DP[z][j]);

            DP[i][j] = min(right, bottom);
        }
    cout << DP[1][1] << "\n";
}
