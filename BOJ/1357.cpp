#include <iostream>

int main()
{
	int X, Y;
	scanf("%d %d", &X, &Y);

	int n = 0;
	int m = 0;

	while (X) {
		n *= 10;
		n += X % 10;
		X /= 10;
	}
	while (Y) {
		m *= 10;
		m += Y % 10;
		Y /= 10;
	}
	int ans = 0;
	int num = n + m;
	while (num) {
		ans *= 10;
		ans += num % 10;
		num /= 10;
	}
	printf("%d", ans);
}