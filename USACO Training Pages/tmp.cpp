#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <list>
using namespace std;

int main(void)
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(6);
    l.push_back(3);

    for(list<int>:: iterator it = l.begin(); it != l.end(); it++)
        if(*it  == 6)
        {
            cout << *(--it) << endl;
            it++;
        }
    return 0;
}