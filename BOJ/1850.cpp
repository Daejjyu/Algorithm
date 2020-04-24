#include <iostream>

int gcd(long long a, long long b)
{
	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	int r = gcd(a, b);
	while (r--)
	{
		printf("1");
	}
}