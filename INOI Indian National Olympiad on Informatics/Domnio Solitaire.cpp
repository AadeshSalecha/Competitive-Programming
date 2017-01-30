/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define INF 1000
#define mp make_pair

const int MAX = 100000 + 7;
int grid[2][MAX], memo[MAX], C;

int maximum(int i)
{
    if(i >= C) return 0;
    if(memo[i] != -1) return memo[i];

    // place 2 tiles horizontally
    int horizontal = (i + 1 < C)? (abs(grid[0][i] - grid[0][i+1])) + (abs(grid[1][i] - grid[1][i+1])) + maximum(i+2) : 0;
    // place tile vertically
    int vertical = (abs(grid[0][i] - grid[1][i])) + maximum(i+1);

    memo[i] = max(vertical, horizontal);
    return memo[i];
}

int main(void)
{
    cin >> C;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            memo[j] = -1;
        }
    cout << maximum(0) << endl;
}
