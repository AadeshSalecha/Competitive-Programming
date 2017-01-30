/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000
#define mp make_pair

const int MAX = 2000 + 7;
vector<int> coded[MAX], ans[MAX];

int main(void)
{
    int N, K, num, cur_set, cur_index;
    cin >> N >> K;

    queue< pair<int, int> > cur;
    for(int i = 0; i < K; i++)
    {
        cin >> num;
        coded[i].resize(num); ans[i].resize(num);
        for(int j = 0; j < num; j++)
        {
            cin >> coded[i][j];
            if(coded[i][j] == 0)
                cur.push(mp(i, j));
            ans[i][j] = -1;
        }
    }

    num = 1;
    while(cur.empty() == false)
    {
        cur_set = cur.front().first, cur_index = cur.front().second; cur.pop();
        ans[cur_set][cur_index] = num++;

        for(int i = 0; i < K; i++)
            if(i != cur_set)
            {
                for(int j = 0; j < coded[i].size(); j++)
                    if(ans[i][j] == -1)
                    {
                        coded[i][j]--;
                        if(coded[i][j] == 0)
                            cur.push(mp(i, j));
                    }
            }
    }

    for(int i = 0; i < K; i++)
    {
        for(int j = 0;j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}