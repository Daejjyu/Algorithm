#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 1000000;

vector<int> temp(MAX);

void merge(vector<int>& arr, int start, int mid, int end)
{
	int firstIndex = start;
	int secondIndex = mid + 1;
	int newIndex = start;

	while (firstIndex <= mid && secondIndex <= end) {
		if (arr[firstIndex] <= arr[secondIndex])
			temp[newIndex++] = arr[firstIndex++];
		else
			temp[newIndex++] = arr[secondIndex++];
	}

	while (firstIndex <= mid)
		temp[newIndex++] = arr[firstIndex++];
	while (secondIndex <= end)
		temp[newIndex++] = arr[secondIndex++];

	for (int i = start; i <= end; i++)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, mid, end);
}

void mergeSort(vector<int>& arr)
{
	mergeSort(arr, 0, arr.size() - 1);
}

int main(void)
{
	int d;
	scanf("%d", &d);

	vector<int> arr(d);

	for (int i = 0; i < d; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergeSort(arr);

	for (int i = 0; i < d; i++)
	{
		printf("%d \n", arr[i]);
	}
}