#include <iostream>

int main(void)
{
	int N, M, val[300], hi = 0, lo = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", val + i);
		hi += val[i];
		if (lo < val[i])lo = val[i];
	}
	lo--;
	while (lo + 1 < hi) {
		int mid = (lo + hi / 2);
		int group = 1;
		int sum = 0;
		bool success = true;
		for (int i = 0; i < N; i++)
		{
			if (sum + val[i] > mid || N - i == M - group) {
				if (group == M) {
					success = false;
					break;
				}
				group++;
				sum = val[i];
			} else
				sum += val[i];
		}
		(success ? hi : lo) = mid;
	}
	printf("%d\n", hi);

	int group = 1;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum + val[i] > hi || N - i == M - group) {
			group++;
			sum = val[i];
			printf("%d ", cnt);
			cnt = 1;
		} else {
			sum += val[i];
			cnt++;
		}
	}
	printf("%d\n", cnt);
}