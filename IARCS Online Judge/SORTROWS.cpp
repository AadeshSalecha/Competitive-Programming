#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	if(a.size() < 1) return true;
	if(b.size() < 1) return false;

	for(int i = 0; i < min(b.size(), a.size()); i++)
		if(a[i] < b[i])
			return true;
		else if(b[i] < a[i])
			return false;
	return (a.size() < b.size());
}

int main(void)
{
	int tmp, N; cin >> N;

	vector< vector<int> > v(N);
	for(int i = 0; i < N; i++)
	{
		while(cin >> tmp and tmp != -1)
			v[i].push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
