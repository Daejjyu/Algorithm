#include<iostream>

int gcd(int N, int M)
{
	while (M) {
		int temp = N % M;
		N = M;
		M = temp;
	}
	return N;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d\n%d", gcd(N, M), N*M / gcd(N, M));
}