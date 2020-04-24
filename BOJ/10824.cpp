#include <iostream>

int main(void)
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int cnt = 0;
	int da = b;
	while (da) {
		cnt++;
		da /= 10;
	}
	while (cnt--) {
		a *= 10;
	}
	cnt = 0;
	da = d;
	while (da) {
		cnt++;
		da /= 10;
	}
	while (cnt--) {
		c *= 10;
	}
	printf("%d", a + b + c + d);
}