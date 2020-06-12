#include <iostream>

long long arr[1000000];

int main()
{
	long long N, M;
	long long lo = 0, hi = 0;
	scanf("%lld %lld", &N, &M);
	for (long long i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		if (arr[i] > hi)
			hi = arr[i];
	}

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (long long i = 0; i < N; i++)
		{
			sum += (arr[i] - mid > 0) ? arr[i] - mid : 0;
		}

		if (sum >= M)
			lo = mid;
		else
			hi = mid;
	}
	printf("%lld", lo);
}