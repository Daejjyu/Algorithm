#include<iostream>

int N;
int arr[101][10];
const int mod = 1e9;
int main()
{
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	arr[1][0] = 0;

	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1] % mod;
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1] % mod;
			else
				arr[i][j] = (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % mod;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += arr[N][i];
		ans %= mod;
	}
	printf("%d", ans);
}