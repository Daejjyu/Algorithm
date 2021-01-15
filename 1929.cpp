#include <iostream>

const int MAX = 1000001;
int arr[MAX] = { -2,-1 }; // -1 이면 소수X
int era[MAX];
void eratoChe()
{
	int count = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] == 0) {
			era[count++] = i;
			for (int j = 2; i*j < MAX; j++)
			{
				arr[i*j] = -1;
			}
		}
	}
}

int main(void)
{
	eratoChe();

	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < sizeof(era) / sizeof(int); i++)
	{
		if (m <= era[i] && era[i] <= n)
			printf("%d\n", era[i]);
		if (era[i] > n)
			break;
	}
}