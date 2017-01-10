/*
    ID: aadesh.1
    PROG: ride
    LANG: C++          
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int prod1=1, prod2=1;
    for(int i =0 ; i < a.size(); i++)
    	prod1 *= (a[i] - 'A' + 1);

    for(int i =0 ; i < b.size(); i++)
    	prod2 *= (b[i] - 'A' + 1);

    if(prod1 % 47 == prod2 % 47)
    	fout << "GO\n";
    else 
    	fout << "STAY\n";
    return 0;
}