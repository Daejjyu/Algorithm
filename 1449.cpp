#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	sort(arr, arr + N);
	int ans = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < start || end < arr[i]) {
			ans++;
			start = arr[i];
			if (start + L - 1 > end)
				end = start + L - 1;
		}
	}
	printf("%d", ans);
}