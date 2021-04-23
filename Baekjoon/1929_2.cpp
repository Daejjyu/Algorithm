#include <iostream>

const int MAX = 1e6 + 1;
int eratho[MAX] = { 1,1 };//0123
int arr[100];

void erathone()
{
	for (int i = 2; i < MAX; i++)
	{
		if (eratho[i] == 0) {
			for (int j = 2; j*i < MAX; j++)
			{
				eratho[i*j] = 1;
			}
		}
	}
}

int main()
{
	erathone();

	int N, M;
	scanf("%d %d", &N, &M);

	int ans = 0;
	for (int i = N; i <= M; i++)
	{
		if (eratho[i] == 0)
			printf("%d\n", i);
	}
}