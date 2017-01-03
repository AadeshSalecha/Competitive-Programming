#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
using namespace std;

const long long MAX = 200 + 7;
pair<long long, long long> machines[MAX][20 +7];

int main(void)
{
	long long num_machines, num_tokens, start, nth, output, next_machine;
	cin >> num_machines >> num_tokens >> start >> nth;

	for(int i = 1; i <= num_machines; i++)
		for(int j = 1; j <= num_tokens; j++)
		{
			cin >> output >> next_machine;
			machines[i][j] = make_pair(output, next_machine);
		}

	// cout << "MACHINES: \n";
	// for(int i = 1; i <= num_machines; i++)
	// {
	// 	cout << i << ": ";
	// 	for(int j = 1; j <= num_tokens; j++)
	// 		cout << j << " " << machines[i][j].first << " " << machines[i][j].second << "\t";
	// 	cout << "\n";
	// }
	// cout << endl;


	vector< pair<long long, long long> > cycle;
	set< pair<long long, long long> > seen;

	long long cur_machine = start, cur_token = 1, cycle_starts_at_machine, cycle_starts_at_token, cycle_index;
	pair<long long, long long> tmp;
	while(true and cycle.size() <= nth)
	{
		if(seen.find(make_pair(cur_machine, cur_token)) != seen.end())
		{
			cycle_starts_at_machine = cur_machine; cycle_starts_at_token = cur_token;
			break;
		}

		cycle.push_back( make_pair(cur_machine, cur_token) );
		seen.insert( make_pair(cur_machine, cur_token) );

		tmp = machines[cur_machine][cur_token];
		cur_machine = tmp.second;
		cur_token = tmp.first;
	}

	// Detect where the cycle starts
	nth--;
	for(int i = 0; i < cycle.size(); i++)
		if(cycle[i].first == cycle_starts_at_machine and cycle[i].second == cycle_starts_at_token)
		{
			cycle_index = i;
			break;
		}

	if(cycle_index > nth)
		cout << cycle[nth].first << "\n"; // << cycle[nth].second <<  "\n";
	else
	{
		nth -= cycle_index;
		cout << cycle[ (nth % (cycle.size() - cycle_index)) + cycle_index ].first << "\n"; // << cycle[ (nth % (cycle.size() - cycle_index)) + cycle_index ].second << "\n";
	}
			
	// cout << "CYCLE: \n";
	// for(int i = 0; i < cycle.size(); i++)
	// 	cout << cycle[i].first << " " << cycle[i].second << "\n";
	// cout << endl;

	// cout << nth << " " << cycle.size() << " " << nth % cycle.size() << "\n";
	// nth--;
	// cout << cycle[nth % cycle.size()] << "\n"; // << cycle[nth % cycle.size()].second << "\n";
	return 0;
}