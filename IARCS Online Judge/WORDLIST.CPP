#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

bool cmp(string a, string b)
{
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
int main(void)
{
	int n; cin >> n;
	string data = "", tmp;
	while(getline(cin, tmp))
	{
		data += " " + tmp;
	}

	set<string> a; int previous = data.find_first_not_of("\n\t\r ,;:.\'");
	string delims = "\n\t\r ,;:.\'";
	for(int i = data.find_first_not_of("\n\t\r ,;:.\'"); i < data.size(); i++)
	{
		if(delims.find(data[i]) != delims.npos)
		{
			string tmp = data.substr(previous, i-previous);
			for(int j = 0; j < tmp.size(); j++)
				if(isupper(tmp[j]))
					tmp[j] = tolower(tmp[j]);

			a.insert(tmp);
			while(delims.find(data[i+1]) != delims.npos)
				i++;
			previous = i+1;
		}
	}
	cout << a.size() << endl;
	vector<string> v(a.begin(), a.end());
	sort(v.begin(), v.end(), cmp);
	for(vector<string>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	return 0;
}