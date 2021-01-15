#include<iostream>
#include<cmath>
using namespace std;

int arr[100000];
int N;

long long sum(long long p)
{
	long long sum = 0;
	for (int i = 1; i < N; i++)
	{
		sum += abs(arr[i] - i * p);
	}
	return sum;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	long long lo = 0, hi = 1e9;
	long long prevL = 0, prevR = 1e9;
	while (lo + 1 < hi) {
		long long left = (2 * lo + hi) / 3;
		long long right = (lo + 2 * hi) / 3;
		if (left == prevL && right == prevR)
			break;
		prevL = left;
		prevR = right;

		sum(left) > sum(right) ? lo = left : hi = right;
	}

	long long ans = sum(lo);
	for (int i = lo; i <= hi; i++)
	{
		if (sum(i) < ans)
			ans = sum(i);
	}
	printf("%lld", ans);
}