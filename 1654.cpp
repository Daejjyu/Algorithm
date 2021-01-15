#include <iostream>

long long arr[10000];

int main()
{
	int K, N;
	scanf("%d %d", &K, &N);
	long long lo = 1, hi = -1;
	for (int i = 0; i < K; i++)
	{
		scanf("%lld", arr + i);
		if (arr[i] > hi)
			hi = arr[i] + 1;
	}

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += arr[i] / mid;
		}
		if (sum >= N)
			lo = mid;
		else
			hi = mid;
	}
	printf("%lld", lo);
}