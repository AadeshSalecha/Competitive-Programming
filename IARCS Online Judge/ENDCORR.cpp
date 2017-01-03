#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

int main(void)
{
	int N, M, num;
	cin >> N >> M;

	priority_queue<int> pq;
	for(int i = 0; i < N+M; i++)
	{
		cin >> num >> ws;
		if(num == -1)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
		else
			pq.push(num);
	}
	return 0;
}
