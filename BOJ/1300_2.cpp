#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	long long lo = -1, hi = 1LL * N * N + 1;

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += min(1LL * N, mid / i);
		}
		if (sum >= K)
			hi = mid;
		else
			lo = mid;
	}
	printf("%lld", hi);
}