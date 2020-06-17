#include<iostream>
#include<algorithm>
using namespace std;

int arr[2000000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N + M);
	for (int i = 0; i < N + M; i++)
	{
		printf("%d ", arr[i]);
	}
}