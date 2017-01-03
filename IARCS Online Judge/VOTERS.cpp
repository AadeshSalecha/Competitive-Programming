#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int a, b, c, tmp, ans = 0;
    cin >> a >> b >> c;

    map<int, int> v;
    for(int i = 0; i < a + b + c; i++)
    {
        cin >> tmp;
        if(v.find(tmp) == v.end())
            v[tmp] = 1;
        else
            v[tmp]++;
    }

    set<int> solution;
    for(map<int, int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if(it->second > 1)
            ans++, solution.insert(it->first);
    }

    cout << ans << "\n";
    for(set<int>::iterator it = solution.begin(); it != solution.end(); it++)
        cout << *it << "\n";
}
