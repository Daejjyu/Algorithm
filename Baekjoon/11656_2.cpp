#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
vector<string> arr;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		arr.push_back(s.substr(i, s.size()));
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < s.size(); i++)
	{
		cout << arr[i] << "\n";
	}
}