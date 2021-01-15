#include <stdio.h>

int main(void)
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	sum += n;
	while (n--) {
		sum += n;
	}
	printf("%d", sum);
}