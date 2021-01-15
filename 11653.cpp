#include <iostream>

const int MAX = 10000001;
int isEra[MAX] = { -2,-1 };
int era[MAX / 10];
int count;

void eratho()
{
	count = 0;
	for (int i = 0; i < MAX; i++)
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

	int d;
	scanf("%d", &d);

	while (d != 1) {
		for (int i = 0; i < count; i++)
		{
			if (d % era[i] == 0) {
				d /= era[i];
				printf("%d\n", era[i]);
				break;
			}
		}
	}
}