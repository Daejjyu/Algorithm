#include <iostream>

int main()
{
	long long n;
	scanf("%lld", &n);

	long long sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += n * i + i;
	}
	printf("%lld", sum);
}