#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int N;
pair<int, int> arr[1000];
int visited[1000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + N, cmp);

	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int day = arr[i].first;
		int score = arr[i].second;
		while (day) {
			if (!visited[day]) {
				sum += score;
				visited[day] = 1;
				cnt++;
				break;
			}
			day--;
		}
	}
	printf("%d", sum);
}