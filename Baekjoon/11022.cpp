#include <stdio.h>

int main(void)
{
	int init, n, a, b;

	scanf("%d", &n);
	init = n;
	while (n--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d", init - n, a, b, a + b);
	}
}