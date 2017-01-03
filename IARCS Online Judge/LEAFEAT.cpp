#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	long long n, result, tmp, k, count = 0; cin >> n >> k;
	vector<int> a;
	while(k--)
	{
		cin >> tmp; a.push_back(tmp);
	}
	// for(int i =0; i < a.size(); i++)
	// 	cout << a[i] << " ";

	for(int i = 0; i < n; i++)
	{
		result = 1;
		for(int j = 0; j < a.size(); j++)
			if(i % a[j] == 0)
			{
				result = 0; break;
			}	
		count += result;
	}
	cout << count << endl;
	return 0;
}