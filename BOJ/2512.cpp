#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10000];

int low = 1e7;
int ans;
long long mid;
int index;
int high;
int maximum;

bool compare(int mid)
{
	long long  num = mid * (N - index);
	if (num <= M) {
		if (mid > maximum)
			maximum = mid;
		return true;
	}

	return false;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] < low)
			low = arr[i];
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	index = 0;
	while (M / (N - index) >= low) {
		for (int i = index; i < N; i++)
		{
			arr[i] -= low;
		}
		M -= (N - index) * low;
		ans += low;
		index++;
		low = arr[index];
		if (N - index == 0)
			break;
	}

	high = M;
	low = 0;
	if (N != index) {
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (compare(mid)) {
				low = mid + 1;
			} else
				high = mid - 1;
		}
	}

	printf("%d", ans + maximum);
}