#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];

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

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (M / (N - i) >= arr[i]) {
			int temp = arr[i];
			for (int j = i; j < N; j++) {
				arr[j] -= temp;
			}
			M -= temp * (N - i);
			ans += temp;
		} else {
			ans += M / (N - i);
			break;
		}
	}
	printf("%d", ans);
}