#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int dpI[1000];
int dpD[1000];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		dpI[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				dpI[i] = max(dpI[i], dpI[j] + 1);
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		dpD[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[i])
				dpD[i] = max(dpD[i], dpD[j] + 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dpI[i] + dpD[i] - 1);
	}
	printf("%d", ans);
}