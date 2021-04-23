#include <stdio.h>

int main(void)
{
	int n, a;
	int sum = 0;
	scanf("%d", &n);

	while (n--) {
		scanf("%1d", &a);
		sum += a;
	}

	printf("%d", sum);
}