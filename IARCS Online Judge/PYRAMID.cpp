#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAX = 1000000 + 7;
int blocks[MAX];

int main(void)
{
//     freopen("inputf.in", "r", stdin);
//     freopen("output.txt", "w", stdout);

    int a, b, N; cin >> N;

    for(int i = 0; i < N; i++)
    {
        scanf("%i %i", &a, &b);
        blocks[i] = min(a, b);
    }

    sort(blocks, blocks + N);

    int cur = 1, ans = 0;
    for(int i = 0; i < N; i++)
    {
        if(blocks[i] >= cur)
            cur++, ans++;
        else 
            i = (lower_bound(blocks, blocks+N, cur) - blocks) - 1;
    }

    printf("%i\n", ans);
}
