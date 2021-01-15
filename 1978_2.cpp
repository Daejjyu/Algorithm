#include <iostream>

const int MAX = 1001;
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

	int N;
	scanf("%d", &N);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		if (eratho[d] == 0)
			ans++;
	}

	printf("%d", ans);
}