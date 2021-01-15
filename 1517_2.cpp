#include<iostream>

int N, arr[500000], temp[500000];
long long ans;

void merge(int s, int e)
{
	int mid = (s + e) / 2;
	int firstIndex = s;
	int secondIndex = mid + 1;
	int newIndex = s;

	while (firstIndex <= mid && secondIndex <= e) {
		if (arr[firstIndex] <= arr[secondIndex])
			temp[newIndex++] = arr[firstIndex++];
		else {
			temp[newIndex++] = arr[secondIndex++];
			ans += 1LL * (mid - firstIndex + 1);
		}
	}

	while (firstIndex <= mid)
		temp[newIndex++] = arr[firstIndex++];
	while (secondIndex <= e)
		temp[newIndex++] = arr[secondIndex++];
	for (int i = s; i <= e; i++)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(int s, int e)
{
	if (s < e) {
		int mid = (s + e) / 2;
		mergeSort(s, mid);
		mergeSort(mid + 1, e);
		merge(s, e);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}
	mergeSort(0, N - 1);

	printf("%lld", ans);
}