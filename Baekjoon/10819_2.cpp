#include<iostream>
#include<algorithm>
using namespace std;

int N, arr[8], ans;

void calculate()
{
	int sum = 0;
	for (int i = 1; i < N; i++)
	{
		sum += abs(arr[i] - arr[i - 1]);
	}
	if (sum > ans)
		ans = sum;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	do {
		calculate();
	} while (next_permutation(arr, arr + N));

	printf("%d", ans);
}