#include<iostream>

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int temp = N - i;
		while (temp) {
			printf(" ");
			temp--;
		}
		for (int j = 1; j <= 2 * i - 1; j++)
			if (j % 2 == 1)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
}