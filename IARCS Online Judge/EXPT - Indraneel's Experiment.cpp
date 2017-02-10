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
#define mp make_pair
using namespace std;
const int MAX = 400;
int a[MAX], b[MAX], DP[MAX][MAX], ans1[MAX], ans2[MAX], N, cnt = -1;

bool match(int i, int j, int prev1, int prev2)
{
    return ((a[i] - prev1) == (b[j] - prev2));
}

int LCS(int a1, int b1, bool print)
{
    for(int i = 0; i <= N; i++)
        DP[a1-1][i] = 0;
    for(int i = 0; i <= N; i++)
        DP[i][b1-1] = 0;
    DP[a1-1][b1-1] = 0;

    int prev1 = a[a1], prev2 = b[b1];
    for(int i = a1; i <= N; i++)
        for(int j = b1; j <= N; j++)
        {
            if(match(i, j, prev1, prev2)) // match
            {
                DP[i][j] = 1 + DP[i-1][j-1];
                prev1 = a[i], prev2 = b[j];
            }
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    if(print)
    {
        int i = N, j = N;
        while(not(i == a1 and j == b1))
        {
            int k = DP[i-1][j], l = DP[i][j-1];
            if(match(i, j, prev1, prev2))
            {
                cnt++; ans1[cnt] = (a[i]); ans2[cnt] = (b[j]);                
                i--; j--;
            }
            else if(k > l)
                i--;
            else
                j--;
        }
        cnt++; ans1[cnt] = (a[i]); ans2[cnt] = (b[j]);                            
    }

    return DP[N][N];
}

int main(void)
{
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> a[i];    
    for(int i = 1; i <= N; i++)
        cin >> b[i];        

    int maxLength = 0, index1 = -1, index2 = -1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            int tmp = LCS(i, j, false);
            if(tmp > maxLength)
                maxLength = tmp, index1 = i, index2 = j;
        }

    cout << maxLength << endl;
    if(index1 == -1 or index2 == -1)
        return 0;
    LCS(index1, index2, true); 

    for(int i = cnt; i >= 0; i--) cout << ans1[i] << " ";
    cout << endl;
    for(int i = cnt; i >= 0; i--) cout << ans2[i] << " ";
    cout << endl;
    return 0;
}