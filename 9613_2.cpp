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
long long arr[100];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", arr + i);
		}
		long long ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				ans += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", ans);
	}
}