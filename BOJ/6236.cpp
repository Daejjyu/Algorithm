#include <iostream>

int arr[100000];
int main(void)
{
	int N, M, hi = 0, lo = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		if (lo < arr[i]) lo = arr[i];
		hi += arr[i];
	}
	lo--;

	while (lo + 1 < hi) {
		int mid = (hi + lo) / 2;
		int sum = 0;
		int group = 1;
		bool success = true;

		for (int i = 0; i < N; i++)
		{
			if (sum + arr[i] > mid || N - i == M - group) {
				if (group == M) {
					success = false;
					break;
				}
				group++;
				sum = arr[i];
			} else
				sum += arr[i];
		}
		(success ? hi : lo) = mid;
	}
	printf("%d", hi);
}