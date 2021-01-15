#include <iostream>

const int MAX = 1000001;
int isEra[MAX] = { -1,-1 };// 0이면 소수
int era[MAX];

void eratho()
{
	int count = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (isEra[i] == 0) {
			era[count++] = i;
			for (int j = i + i; j < MAX; j += i)
			{
				isEra[j] = -1;
			}
		}
	}
}

int main(void)
{
	eratho();

	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		bool notGold = true;
		for (int i = 0; i < sizeof(era) / sizeof(int); i++)
		{
			if (era[i] < n && isEra[n - era[i]] == 0) {
				printf("%d = %d + %d\n", n, era[i], n - era[i]);
				notGold = false;
				break;
			}
		}
		if (notGold)
			printf("Goldbach's conjecture is wrong.\n");
	}
}