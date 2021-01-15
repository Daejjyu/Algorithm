#include<iostream>

int arr[100000];

int N, M;

bool possible(int mid)
{
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)
			return false;
		sum += arr[i];
		if (sum > mid) {
			sum = arr[i];
			cnt++;
		}
	}
	return M >= cnt;
}

int main()
{
	scanf("%d %d", &N, &M);
	int lo = 0, hi = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		hi += arr[i];
	}

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (possible(mid))
			hi = mid;
		else
			lo = mid;
	}
	printf("%d", hi);
}