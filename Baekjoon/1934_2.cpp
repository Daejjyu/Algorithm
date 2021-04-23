#include<iostream>

long long gcd(long long N, long long M)
{
	while (M) {
		long long temp = N % M;
		N = M;
		M = temp;
	}
	return N;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long N, M;
		scanf("%lld %lld", &N, &M);
		printf("%lld\n", N*M / gcd(N, M));
	}
}