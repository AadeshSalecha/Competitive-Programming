#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <numeric>
using namespace std;

const int MAX = 1000000+7;
int books[MAX];

int main(void)
{
//	freopen("inputf.in", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N, Q, tmp;
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> books[i];

	cin >> Q;
	set<int> entries;
	for(int i = 0; i < Q; i++)
	{
		cin >> tmp;
		for(set<int>::iterator it = entries.begin(); it != entries.end(); it++)
        {
            if(*it <= tmp)
                tmp++;
            else
                break;
		}
        entries.insert(tmp);
        cout << books[tmp] << endl;
	}
	return 0;
}
