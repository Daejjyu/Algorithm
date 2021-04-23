#include<iostream>
#include<algorithm>
using namespace std;

int N, arr[100000];

int square(int s, int e)
{
	if (s + 1 == e) return arr[s];

	int mid = (s + e) / 2;
	int ret = max(square(s, mid), square(mid, e));

	int len = 1, minValue = arr[mid];
	for (int lo = mid, hi = mid; lo > s || hi < e - 1;) {
		if (lo == s || hi < e - 1 && arr[lo - 1] < arr[hi + 1]) {
			minValue = min(minValue, arr[++hi]);
		} else {
			minValue = min(minValue, arr[--lo]);
		}
		ret = max(ret, ++len*minValue);
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

	printf("%d", square(0, N));
}