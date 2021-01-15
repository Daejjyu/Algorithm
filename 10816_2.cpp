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

		int a = lower_bound(arr, arr + N, num) - arr + 1;
		int b = upper_bound(arr, arr + N, num) - arr + 1;
		printf("%d ", b - a);
	}
}