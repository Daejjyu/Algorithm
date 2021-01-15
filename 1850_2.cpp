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
	long long N, M;
	scanf("%lld %lld", &N, &M);
	int T = gcd(N, M);
	while (T--) {
		printf("1");
	}
}