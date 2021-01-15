#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

pair<int, pair<int, string>> arr[100000];

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
	if (a.second.first == b.second.first)
		return a.first < b.first;
	return a.second.first < b.second.first;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		arr[i].first = i;
		cin >> arr[i].second.first >> arr[i].second.second;
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].second.first << " " << arr[i].second.second << "\n";
	}
}