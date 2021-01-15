#include <iostream>

long long N, M;
long long high, low;
long long  maxLen;
long long mid;

long long tree[1000000];

bool compare(long long mid)
{
	long long temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] > mid)
			temp += tree[i] - mid;
	}
	if (temp >= M)
		return true;
	else
		return false;
}

int main(void)
{
	scanf("%lld %lld", &N, &M);
	for (long long i = 0; i < N; i++)
	{
		scanf("%lld", &tree[i]);
		if (high < tree[i])
			high = tree[i];
	}

	while (low <= high) {
		mid = low + (high - low) / 2;
		if (compare(mid)) {
			if (maxLen < mid)
				maxLen = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	printf("%lld", maxLen);
}