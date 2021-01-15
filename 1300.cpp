#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	long long lo = 1, hi = 1LL * N * N;
	lo--;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 1; i <= N; i++)
		{
			long long index;
			mid < i*N ? index = mid : index = i * N;
			if (index >= i) sum += index / i;
		}
		if (sum >= K)
			hi = mid;
		else
			lo = mid;
	}
	printf("%lld", hi);
}