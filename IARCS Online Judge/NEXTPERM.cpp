#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <sstream>
using namespace std;

int main(void)
{
	int n, k, tmp; cin >> n >> k >> ws;
	string data;
	while(k--)
	{
		getline(cin, data);
		stringstream ss; ss << data;
		vector<int> a;
		while(ss >> tmp)
			a.push_back(tmp);

		next_permutation(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
		cout << endl; 
	}
	return 0;
}