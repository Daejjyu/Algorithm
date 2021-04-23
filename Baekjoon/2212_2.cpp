#include<iostream>
#include<algorithm>
using namespace std;

int N, K, arr[10000], dist[10000];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	for (int i = 0; i < N - 1; i++)
	{
		dist[i] = arr[i + 1] - arr[i];
	}
	sort(dist, dist + N - 1);

	int sum = 0;
	for (int i = 0; i < N - K; i++)
	{
		sum += dist[i];
	}
	printf("%d", sum);
}