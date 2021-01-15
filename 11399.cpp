#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += arr[i] * (N - i);
	}
	printf("%d", ans);
}