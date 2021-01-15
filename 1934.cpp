#include <iostream>

int gcd(int a, int b)
{
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int a, b;
	while (n--)
	{
		scanf("%d %d", &a, &b);
		int g = gcd(a, b);
		printf("%d\n", g*a / g * b / g);
	}
}