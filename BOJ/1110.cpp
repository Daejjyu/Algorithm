#include <iostream>

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 0;
	int idx = N;
	while (N != idx || ans == 0) {
		int M = idx % 10;
		M += idx / 10;

		idx = 10 * (idx % 10) + M % 10;
		ans++;
		printf("N%d idx%d ans%d\n", N, idx, ans);
	}

	printf("%d", ans);
}