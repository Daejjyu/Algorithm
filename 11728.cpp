#include <cstdio>

const int MAX = 1000000;

int N, M;
int arr1[MAX];
int arr2[MAX];
int ans[MAX];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr1 + i);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d", arr2 + i);
	}

	int fstIdx = 0, secondIdx = 0, ansIdx = 0;
	while (fstIdx < N && secondIdx < M) {
		if (arr1[fstIdx] < arr2[secondIdx])
			ans[ansIdx++] = arr1[fstIdx++];
		else ans[ansIdx++] = arr2[secondIdx++];
	}
	while (fstIdx < N)
		ans[ansIdx++] = arr1[fstIdx++];
	while (secondIdx < M)
		ans[ansIdx++] = arr2[secondIdx++];

	for (int i = 0; i < N + M; i++)
	{
		printf("%d ", ans[i]);
	}
}