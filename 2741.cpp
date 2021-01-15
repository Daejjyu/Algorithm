#include <stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);
	int init = 0;
	while (n--)
		printf("%d\n", ++init);
}