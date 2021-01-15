#include<iostream>
#include<algorithm>
using namespace std;

int N, K, D;
int s[1000000];
int e[1000000];
int range[1000000];

bool possible(int mid)
{
	long long sum = 0;
	for (int i = 0; i < K; i++)
	{
		int last = (mid < e[i]) ? mid : e[i];

		if (s[i] <= last) {
			sum += (last - s[i]) / range[i];
			sum++;
		}
	}
	return sum >= D;
}

int main()
{
	scanf("%d %d %d", &N, &K, &D);
	int lo = N, hi = 0;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d", s + i, e + i, range + i);
		lo = min(lo, s[i]);
		hi = max(hi, e[i]);
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