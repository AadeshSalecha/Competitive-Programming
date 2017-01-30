/*
  Author    : Aadesh Salecha
  Site      : Indian National Olympiad on Informatics
  Created   : January 2017
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define INF 1000
#define mp make_pair

const int MAX = 1000000 + 7;
pair<int, int> nums[MAX];

int main(void)
{
    int N, pos = 0, entry, gone; cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> entry >> gone;
        nums[pos++] = mp(entry, +1);
        nums[pos++] = mp(gone, -1);
    }

    sort(nums, nums + pos);

    int ans = 0, sum = 0;
    for(int i = 0; i < pos; i++)
    {
        sum += nums[i].second;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
