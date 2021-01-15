#include<iostream>
#include<algorithm>
using namespace std;

int N, arr[100000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, (N - i)*arr[i]);
	}
	printf("%d", ans);
}