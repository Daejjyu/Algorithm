#include <iostream>

const int MAX = 100;

int arr[MAX];
int t, n, a, b;

int gcd(int a, int b)
{
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int gcdSum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				gcdSum += gcd(arr[i], arr[j]);
			}
		}
		printf("%d\n", gcdSum);
	}
}