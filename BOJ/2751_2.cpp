#include <iostream>
using namespace std;

int arr[1000000];

void quickSort(int start, int end)
{
	if (start >= end) return;

	int left = start;
	int right = end;
	int pivot = arr[start + (end - start) / 2];

	while (left <= right) {
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
			swap(arr[left++], arr[right--]);
	}

	quickSort(start, right);
	quickSort(left, end);
}

int main(void)
{
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d);
		arr[i] = d;
	}
	quickSort(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d \n", arr[i]);
	}
}