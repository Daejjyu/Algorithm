#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<string> arr;
	for (size_t i = 0; i < s.length(); i++)
	{
		arr.push_back(s.substr(i, s.length()));
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\n";
	}
}