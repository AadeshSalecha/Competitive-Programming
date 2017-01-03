#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isPunctuation(char c)
{
    return (c == '\'' or c == '.' or c == ',' or c == ';' or c == ':');
}

int main(void)
{
    // freopen("inputf.in", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N; cin >> N >> ws;
    string data, tmp;
    char c;

    vector< vector<string> > ans;
    for(int i = 0; i < N; i++)
    {
        getline(cin, tmp);
        for(int i = 0; i < tmp.size(); i++)
        {
            if(!isPunctuation(tmp[i]))
                data += tmp[i];
            else
                data += " ";
        }
        stringstream ss; ss << data;
        vector<string> v;

        while(ss >> tmp)
            v.push_back(tmp);
        ans.push_back(v);
        data = "";
    }

    for(int i = ans.size()-1; i >= 0; i--)
    {
        for(int j = ans[i].size()-1; j >= 0; j--)
            cout << ans[i][j] << " ";
        cout << endl;
    }
//    cout << data << "\n";
}
