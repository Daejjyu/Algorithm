#include <stdio.h>

int main(void)
{
	int n, left, right;
	scanf("%d", &n);

	left = n;
	right = n;

	for (int i = 1; i < n; i++)
	{
		for (int i = 1; i <= right; i++)
		{
			if (i == left || i == right)
				printf("*");
			else
				printf(" ");
		}

		left--;
		right++;
		printf("\n");
	}

	int length = 2 * n - 1;
	while (length--)
		printf("*");
}