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
		for (int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}

	for (int i = N - 1; i >= 1; i--)
	{
		int temp = N - i;
		while (temp) {
			printf(" ");
			temp--;
		}
		for (int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}