#include <stdio.h>

int main(void)
{
	int n, d, sum;
	sum = 0;
	scanf("%d", &d);
	while (~scanf("%1d", &d))
		sum += d;
	/*scanf("%d", &n);
	while (n--) {
		scanf("%1d", &d);
		sum += d;
	}*/
	printf("%d", sum);
}