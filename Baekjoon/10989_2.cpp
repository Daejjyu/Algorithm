#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];

int main()
{
	int N, lo = 1e8, hi = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		lo = min(lo, d);
		hi = max(hi, d);
		arr[d]++;
	}

	for (int i = lo; i <= hi; i++)
	{
		while (arr[i]) {
			printf("%d\n", i);
			arr[i]--;
		}
	}
}