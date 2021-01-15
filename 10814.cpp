#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
		return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}