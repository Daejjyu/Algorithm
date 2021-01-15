#include <iostream>

int lesson[100000];
int main(void)
{
	int N, M, hi = 0, lo = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", lesson + i);
		hi += lesson[i];
		if (lo < lesson[i]) lo = lesson[i];
	}
	lo--;

	while (lo + 1 < hi) {
		int blue = 1, sum = 0;
		int mid = (lo + hi) / 2;
		bool success = true;
		for (int i = 0; i < N; i++)
		{
			if (sum + lesson[i] > mid || N - i == M - blue) {
				if (M == blue) {
					success = false;
					break;
				}
				blue++;
				sum = lesson[i];
			} else
				sum += lesson[i];
		}
		(success ? hi : lo) = mid;
	}
	printf("%d", hi);
}