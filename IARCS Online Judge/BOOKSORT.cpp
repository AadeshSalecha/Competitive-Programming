#include <iostream>
#include <cstdio>
using namespace std;
#define INF 10000
const int MAX = 200000 + 7;
int LIS[MAX];

int main(void)
{
    int N, tmp, pos = 0, best = 0;
    scanf("%i", &N);

    scanf("%i", &LIS[0]);
    for(int i = 1; i < N; i++)
    {
        scanf("%i", &tmp);

        if(tmp >= LIS[pos])
            pos++, LIS[pos] = tmp;
        else
            LIS[lower_bound(LIS, LIS+pos, tmp) - LIS] = tmp;

        best = max(best, pos+1);

    }
    printf("%i\n", N - best);
}
