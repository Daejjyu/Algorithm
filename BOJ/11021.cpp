#include <stdio.h>

int main(void)
{
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", 5 - n, a + b);
	}
}