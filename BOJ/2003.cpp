#include<iostream>
using namespace std;

int arr[10000];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}

	int lo = 0, hi = 0;
	int sum = 0, cnt = 0;
	while (lo < N) {
		if (sum < M && hi < N) {
			sum += arr[hi++];
		} else {
			if (sum == M)
				cnt++;
			sum -= arr[lo++];
			if (lo > hi) {
				hi = lo;
				sum = 0;
			}
		}
	}
	printf("%d", cnt);
}