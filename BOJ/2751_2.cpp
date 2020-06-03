#include <iostream>

const int MAX = 1e6 + 1;
int arr[MAX];
int temp[MAX];

void quickSort(int s, int e)
{
	if (s < e) {
		int pivot = arr[(s + e) / 2];
		int left = s;
		int right = e;

		while (left < right) {
			while (arr[left] < pivot)
				left++;
			while (arr[right] > pivot)
				right--;
			if (left <= right)
				std::swap(arr[left++], arr[right--]);
		}

		quickSort(s, right);
		quickSort(left, e);
	}
}

void merge(int s, int e)
{
	int mid = (s + e) / 2;
	int index1 = s;
	int index2 = mid + 1;
	int indexTemp = s;

	while (index1 <= mid && index2 <= e) {
		if (arr[index1] < arr[index2])
			temp[indexTemp++] = arr[index1++];
		else
			temp[indexTemp++] = arr[index2++];
	}

	while (index1 <= mid)
		temp[indexTemp++] = arr[index1++];
	while (index2 <= e)
		temp[indexTemp++] = arr[index2++];

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
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	//mergeSort(0, N - 1);
	quickSort(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
}