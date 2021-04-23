#include <iostream>

int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	int gcd1 = gcd(a, b);
	printf("%d\n%d", gcd1, gcd1*(a / gcd1)*(b / gcd1));
}