#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	sort(arr, arr + N);
	printf("%d", arr[K - 1]);
}