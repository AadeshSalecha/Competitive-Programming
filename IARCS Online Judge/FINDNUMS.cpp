#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

int main(void)
{
	int k, S, P;
	cin >> S >> P >> k;

	bool ans = false;
	if(k == 1)
	{
		ans = (S == P);
		if(ans)
			cout << P << "\n";
		else
			cout << "NO\n";
	}
	if(k == 2)
	{
		for(int i = 1; i*i <= P and !ans; i++)
			for(int j = i; j*i <= P and !ans; j++)
				if(i + j == S and P == i * j)
				{
					cout << i << " " << j << "\n";
					ans = true;
				}
		if(!ans)
			cout << "NO\n";		
	}
	if(k == 3)
	{
		for(int i = 1; i*i*i <= P and !ans; i++)
			for(int j = i; i*i*j <= P and !ans; j++)
				for(int k = j; i*i*k <= P and !ans; k++)
					if(i + j + k == S and i * j * k == P)
					{
						cout << i << " " << j << " " << k << "\n";
						ans = true;
					}
		if(!ans)
			cout << "NO\n";			
	}
	if(k == 4)
	{
		for(int i = 1; i*i*i*i <= P and !ans; i++)
			for(int j = i; i*i*i*j <= P and !ans; j++)
				for(int k = j; i*i*i*k <= P and !ans; k++)
					for(int l = k; i*i*i*l <= P and !ans; l++)
						if(i + j + k + l == S and i * j * k * l == P)
						{
							cout << i << " " << j << " " << k << " " << l << "\n";
							ans = true;
						}
		if(!ans)
			cout << "NO\n";				
	}
	return 0;
}