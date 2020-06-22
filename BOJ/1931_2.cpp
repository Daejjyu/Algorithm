#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + N, cmp);

	int last = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (last <= arr[i].first) {
			ans++;
			last = arr[i].second;
		}
	}
	printf("%d", ans);
}