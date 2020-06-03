#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

pair<pair<string, int>, pair<int, int>> arr[100000];

bool cmp(pair<pair<string, int>, pair<int, int>>  a, pair<pair<string, int>, pair<int, int>>  b)
{
	if (a.first.second == b.first.second) {
		if (a.second.first == b.second.first) {
			if (a.second.second == b.second.second)
				return a.first.first < b.first.first;
			return a.second.second > b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first.second > b.first.second;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first.first << "\n";
	}
}