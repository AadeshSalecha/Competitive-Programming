/*
    ID: aadesh.1
    PROG: friday
    LANG: C++          
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days[7] = {0};

bool isLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));    
}   

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("ride.in");
    int year, elapsed = 0; fin >> year;
    for(int i = 1900; i < year+1900; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            days[(elapsed+13) % 7]++;
            // cout << "13th of " << j+1 << " is" << elapsed % 7 << endl;
            elapsed += months[j];
            if(j == 1) elapsed += int(isLeap(i));
            // cout << elapsed << " ";
        }
    }
    // cout << endl << isLeap(1900) << endl;
    for(int i = 6; i < 13; i++)
        if(i < 12)
            fout << days[i % 7] << " ";
        else
            fout << days[i % 7];
    fout << endl;
}