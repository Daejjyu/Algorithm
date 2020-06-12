#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];

int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	int lo = 0, hi = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		if (arr[i] > hi)
			hi = arr[i];
	}
	sort(arr, arr + N);
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = 1;
		int cur = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - cur >= mid) {
				cnt++;
				cur = arr[i];
			}
		}
		if (cnt >= C)
			lo = mid;
		else
			hi = mid;
	}
	printf("%d", lo);
}