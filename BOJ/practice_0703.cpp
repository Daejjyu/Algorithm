#include<iostream>
#include<algorithm>
using namespace std;

int K, N, arr[10000];
int main()
{
	scanf("%d %d", &K, &N);

	long long lo = 1, hi = 0;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", arr + i);
		hi = max(hi, 1LL * arr[i]);
	}
	hi++;

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += arr[i] / mid;
		}
		if (sum >= N)
			lo = mid;
		else
			hi = mid;
	}

	printf("%d", lo);
}