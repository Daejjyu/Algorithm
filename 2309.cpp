#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];
int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", arr + i);
		sum += arr[i];
	}

	sort(arr, arr + 9);
	int idx1, idx2;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100) {
				sum -= arr[i];
				idx1 = i, idx2 = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != idx1 && i != idx2)
			printf("%d\n", arr[i]);
	}
}