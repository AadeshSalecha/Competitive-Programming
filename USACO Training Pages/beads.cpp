/*
    ID: aadesh.1
    PROG: beads
    LANG: C++          
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n; fin >> n;
    string s; fin >> s;
    int i = min(find(s.begin(), s.end(), 'r')-s.begin(), find(s.begin(), s.end(), 'b')-s.begin());
    int maximum = 0, previous = 0, current = i, first_change = 0, first_value = 0; 
    char first_letter, current_letter = s[i];
    // fout<< current_letter << " " << i << current << endl;
    for(;i < s.size() ; i++)
    {
        if(s[i % (s.size())] == current_letter || s[i % (s.size())] == 'w')
            current++;
        else
        {
            if(first_change == 0) 
            {
                first_change = i;
                first_letter = current_letter;
                first_value = current;
            }
            current_letter = s[i % s.size()]; 
            maximum = max(maximum, current + previous);
            previous = current;
            current = 1;
        }
        // fout<< i << " " << previous << " " << current << " " << maximum << endl;
    }
    maximum = max(maximum, current + previous);  
    current = first_value; current_letter = first_letter;
    for(i = s.size()-1; i >= 0; i--)
    {
        if(s[i] != current_letter && s[i] != 'w') 
            break;    
        current++;
    }
    previous = current; current = 0; current_letter = s[i];
    for(;i >= first_change; i--)
    {
        if(s[i] != current_letter && s[i] != 'w') 
            break;
        current++;
    }
    maximum = max(maximum, current + previous);   
    fout<< maximum << endl;
}
