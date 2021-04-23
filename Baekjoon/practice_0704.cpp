#include<iostream>
#include<algorithm>
using namespace std;

int N, M, arr[500000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int d;
		scanf("%d", &d);
		int lo = 0, hi = N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] > d)
				hi = mid;
			else
				lo = mid;
		}
		printf("%d ", d == arr[lo] ? 1 : 0);
	}
}