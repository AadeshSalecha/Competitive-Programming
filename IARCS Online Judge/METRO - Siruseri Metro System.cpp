/*
  Author    : Aadesh Salecha
  Site      : IARCS.org
  Created   : Febuary 2017
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#define mp make_pair
#define ii pair<int, int>
#define xc first
#define yc second
#define INF 1000000
using namespace std;
const int MAX = 50 + 7;

struct cmp
{
	bool operator()(pair<int, ii > a, pair<int, ii > b)
	{
		return a.first > b.first;
	}
};

int N, M, D[MAX][MAX];
map<char, int> speed;
ii Tc[MAX], Tr[MAX];
priority_queue< pair<int, ii >, vector< pair<int, ii > >, cmp> pq;


int getTime(int sta, int mint, int stime, int gap, int n)
{
        int r,s,time1,n2;

        r = (sta*gap)+stime;
        s = mint - r;
        if(s < 0) return r;
        
        n2 = (n*2)-2;
        n2 = n2 * gap;
        time1 = s/n2;
        time1++;
        time1 = time1*n2 + r;
        return time1;
}

void Relax(ii u, ii v, int dist)
{
	if(D[v.xc][v.yc] > dist)
	{
		D[v.xc][v.yc] = dist;	
		pq.push(mp(D[v.xc][v.yc], mp(v.xc, v.yc)));
	}
}

int Dijkstra(ii a, ii b, int at_time)
{
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= M; j++)
			D[i][j] = INF;
	
	D[a.xc][a.yc] = at_time;
	pq.push(mp(at_time, mp(a.xc, a.yc)));

	int cur_time, dist; ii cur, u, v;
	while(!pq.empty()) // and !(i == b.xc and j == b.yc))
	{
		cur = pq.top().second, cur_time = pq.top().first; pq.pop();
		int i = cur.xc, j = cur.yc;
		if(cur_time > D[i][j]) continue;

		// generate all edges		
		if(i-1 >= 0) // ip i-1, j
		{
			u = cur, v = mp(i-1, j);
			if(i-1 == 0)
	            dist = getTime(i-1,D[i][j], Tc[j].second, Tc[j].first, M);
            else
	            dist = getTime(M-1 + (M-i), D[i][j], Tc[j].second, Tc[j].first, M);
			Relax(u, v, dist);
		}
		if(i+1 < M) // down i+1, j
		{
			u = cur, v = mp(i+1, j);
			dist = getTime(i+1, D[i][j], Tc[j].second, Tc[j].first, M);
			Relax(u, v, dist);
		}
		if(j-1 >= 0) // left i, j-1
		{
			u = cur, v = mp(i, j-1);
			if(j-1 == 0)
                dist = getTime(j-1, D[i][j], Tr[i].second, Tr[i].first, N);
            else 
                dist = getTime(N-1 + (N-j), D[i][j], Tr[i].second, Tr[i].first, N);
			Relax(u, v, dist);
		}
		if(j+1 < N) // right i, j+1
		{
			u = cur, v = mp(i, j+1);
			dist = getTime(j+1, D[i][j], Tr[i].second, Tr[i].first, N);
			Relax(u, v, dist);
		}
	}
	return D[b.xc][b.yc];
}

int main(void)
{
	int start, x1, y1, cur_time, x2, y2; char s;
	cin >> M >> N;	
	speed['F'] = 1; speed['O'] = 2; speed['S'] = 3;
	for(int i = 0; i < M; i++)
	{
		cin >> s >> start;
		Tr[i] = mp(speed[s], start);
	}
	for(int i = 0; i < N; i++)
	{
		cin >> s >> start;
		Tc[i] = mp(speed[s], start);
	}
	cin >> x1 >> y1 >> cur_time >> x2 >> y2;
	cout << Dijkstra(mp(x1-1, y1-1), mp(x2-1, y2-1), cur_time) << endl;
	return 0;
}