#include <iostream>

const int MAX = 1e6 + 1;
int era[MAX] = { 1,1 };

void eratho()
{
	for (int i = 2; i < MAX; i++)
	{
		if (era[i] == 0)
		{
			for (int j = 2; i*j < MAX; j++)
			{
				era[i*j] = 1;
			}
		}
	}
}

int main()
{
	eratho();

	while (1) {
		int N;
		scanf("%d", &N);
		if (N == 0)
			break;
		bool possible = false;
		for (int i = 2; i <= N / 2; i++)
		{
			if (era[i] + era[N - i] == 0) {
				printf("%d = %d + %d\n", N, i, N - i);
				possible = true;
				break;
			}
		}
		if (!possible)
			printf("Goldbach's conjecture is wrong.");
	}
}