/*
    ID: aadesh.1
    PROG: gift1
    LANG: C++          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n, init, num_friends; fin >> n;
    string names[n], name, _friend;
    std::map<string, pair<int, int> > data;
    for(int i =0; i < n; i++)
    {
    	fin >> names[i]; data[names[i]].second = 0;
    }
    for(int i = 0; i < n; i++)
    {
    	fin >> name >> init >> num_friends;
    	data[name].first = (init);
    	if(num_friends != 0)
    		data[name].second += (init % num_friends);
    	for(int j = 0; j < num_friends; j++)
    	{
    		fin >> _friend; data[_friend].second += (init / num_friends);
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	fout << names[i] << " " << data[names[i]].second - data[names[i]].first << endl;
    }
    return 0;
}