#include<iostream>
#include<string>
using namespace std;

string eight[8] = { "000", "001","010","011","100","101","110","111" };
string eight1[8] = { "0", "1","10","11","100","101","110","111" };
int two[8] = { 0,1,2,3,4,5,6,7 };
int main()
{
	string s;
	cin >> s;

	for (int j = 0; j < 9; j++)
	{
		if (s[0] == two[j] + '0') {
			cout << eight1[j];
			break;
		}
	}
	for (int i = 1; i < s.size(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (s[i] == two[j] + '0') {
				cout << eight[j];
				break;
			}
		}
	}
}