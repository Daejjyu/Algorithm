#include <iostream>

int N, M;
int arr[100000];

bool possible(int mid)
{
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)
			return false;
		sum += arr[i];
		if (sum > mid) {
			cnt++;
			sum = arr[i];
			if (sum == mid)
				sum = 0;
		}
	}
	return cnt <= M;
}

int main()
{
	scanf("%d %d", &N, &M);
	int lo = 0, hi = 0;
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
	printf("%d", hi);
}