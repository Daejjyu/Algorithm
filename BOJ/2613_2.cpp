#include <iostream>

int N, M;

int arr[300];

bool possible(int size)
{
	int grp = 1;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > size)
			return false;
		sum += arr[i];
		if (N - i == M - grp) {
			grp++;
		} else if (sum > size) {
			grp++;
			sum = arr[i];
		}
	}
	return grp <= M;
}

int main()
{
	scanf("%d %d", &N, &M);
	int lo = -1, hi = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		hi += arr[i];
	}

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (possible(mid))
			hi = mid;
		else
			lo = mid;
	}

	printf("%d\n", hi);

	int grp = 1;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cnt++;
		sum += arr[i];
		if (N - i == M - grp) {
			grp++;
			printf("%d ", cnt - 1);
			cnt = 1;
		} else if (sum > hi) {
			grp++;
			sum = arr[i];
			printf("%d ", cnt - 1);
			cnt = 1;
		}
	}
	printf("%d", cnt);
}