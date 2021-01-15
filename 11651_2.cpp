#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> arr[100000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
}