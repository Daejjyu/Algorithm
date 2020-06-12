#include<iostream>
#include<algorithm>
using namespace std;

int arr[500000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		int lo = 0, hi = N;
		bool possible = false;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] > num)
				hi = mid;
			else
				lo = mid;
		}
		if (arr[lo] == num) {
			possible = true;
		}
		if (possible)
			printf("1 ");
		else
			printf("0 ");
	}
}