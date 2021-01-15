#include <iostream>

int main()
{
	int K, N, M;
	scanf("%d %d %d", &K, &N, &M);

	int ans = K * N - M;
	if (ans < 0)
		printf("%d", 0);
	else
		printf("%d", ans);
}