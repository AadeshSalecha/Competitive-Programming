#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 10000
const int MAX = 45000 + 7;
int elements[MAX];

int main(void)
{
    int N, tmp, pos = 0, i;
    scanf("%i", &N);

    while(N--)
    {
        scanf("%i", &elements[pos++]);

        // do insertion sort to place it in the right position
        i = pos-1;
        while(elements[i] > elements[i-1] and i > 0)
            swap(elements[i], elements[i-1]), i--;

        printf("%i\n", i+1);
    }
}