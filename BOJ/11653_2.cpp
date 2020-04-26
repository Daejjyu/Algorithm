#include <iostream>
int const MAX = 10000001;

int isEra[MAX] = { -1,-1 };
int era[MAX / 10];

void eratho()
{
	int count = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (isEra == 0) {
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
	int n;
	scanf("%d", &n);

	int i = 0;
	while (n)
	{
		if (n % era[i] == 0)
		{
			n /= era[i];
			printf("%d", era[i]);
		}

		else
			i++
	}
}