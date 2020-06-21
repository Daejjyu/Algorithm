#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long N, arr[100000];

long long dist(long long num)
{
	long long sum = 0;
	for (int i = 1; i < N; i++)
	{
		sum += abs(arr[0] + i * num - arr[i]);
	}
	return sum;
}

int main()
{
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", arr + i);
	}

	long long lo = 0, hi = 1e9;
	while (lo + 2 < hi) {
		long long left = (2 * lo + hi) / 3;
		long long right = (lo + 2 * hi) / 3;

		(dist(left) > dist(right)) ? lo = left : hi = right;
	}
	long long ans = dist(hi);
	for (int i = lo; i < hi; i++)
	{
		ans = min(ans, dist(i));
	}
	printf("%lld", ans);
}