#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define INF 10000

const int MAX = 1000000;
long long f[MAX], g[MAX];
const int MOD = 10000;

int main(void)
{
    int N; cin >> N;

    f[0] = 1;          g[0] = 0;
    f[1] = 1;          g[1] = 1;
    f[2] = 2;          g[2] = 2;

    for(int i = 3; i <= N; i++)
    {
        // f(n) = f(n-1) + f(n-2) + 2*g(n-2)
        f[i] = (((f[i-1] % MOD) + (f[i-2] % MOD) + (((2 % MOD) * (g[i-2] % MOD)) % MOD)) % MOD); // (g[i-2] % MOD) + (g[i-2] % MOD)

        // g(n) = f(n-1) + g(n-1)
        g[i] = (((f[i-1] % MOD) + (g[i-1] % MOD)) % MOD);
    }
    cout << f[N] % MOD << endl;
}
