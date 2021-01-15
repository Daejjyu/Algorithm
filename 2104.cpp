#include<iostream>
#include<algorithm>
using namespace std;

int N, arr[100000];

long long score(int s, int e)
{
	if (s + 1 == e) return arr[s] * arr[s] * 1LL;

	int mid = (s + e) / 2;
	long long ret = max(score(s, mid), score(mid, e));

	long long sum = arr[mid]; int minValue = arr[mid];
	ret = max(ret, sum*minValue);
	for (int lo = mid, hi = mid; lo > s || hi < e - 1;) {
		if (lo == s || hi < e - 1 && arr[lo - 1] < arr[hi + 1]) {
			sum += arr[++hi];
			minValue = min(minValue, arr[hi]);
		} else {
			sum += arr[--lo];
			minValue = min(minValue, arr[lo]);
		}
		ret = max(ret, sum*minValue);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	printf("%lld", score(0, N));
}