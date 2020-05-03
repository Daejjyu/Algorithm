#include <iostream>
#include <algorithm>
using namespace std;

int const MAX = 1000000;
int s1[MAX], s2[MAX], gap[MAX];

int main(void)
{
	int N, K, D, lo = 1e9, hi = 0;
	scanf("%d %d %d", &N, &K, &D);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d", s1 + i, s2 + i, gap + i);
		if (s1[i] < lo)
			lo = s1[i];
		if (hi < s2[i])
			hi = s2[i];
	}
	lo--;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++)
		{
			int high = min(s2[i], mid);

			if (high >= s1[i])
				sum += ((high - s1[i]) / gap[i]) + 1;
		}
		if (sum >= D)
			hi = mid;
		else
			lo = mid;
	}
	printf("%d", hi);
}