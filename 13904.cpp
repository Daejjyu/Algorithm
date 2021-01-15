#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[1001];
int score[1001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int d, w;
		scanf("%d %d", &d, &w);
		if (d > N)
			d = N;
		arr[i].first = d;
		arr[i].second = w;
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		int idx = arr[i].first;
		while (idx >= 1) {
			if (score[idx] == 0) {
				score[idx] = arr[i].second;
				break;
			} else
				idx--;
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += score[i];
	}
	printf("%d", sum);
}