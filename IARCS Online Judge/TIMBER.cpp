#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

const int MAX = 1000  + 7;
int grid[MAX][MAX];

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, M, Q, tmp, x1, y1, x2, y2;
    scanf("%i %i", &N, &M);

    for(int i = 0; i <= M; i++)
        grid[0][i] = grid[i][0] = 0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            scanf("%i", &grid[i][j]);
            grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }

    scanf("%i", &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
        tmp = grid[x2][y2] - grid[x2][y1-1] - grid[x1-1][y2] + grid[x1-1][y1-1];
        printf("%i\n", tmp);
    }
}
