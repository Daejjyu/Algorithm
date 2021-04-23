#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int arr[5000000];

int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);

	int k;
	for (int i = 0; i < x; i++)
	{
		scanf("%d", &k);
		arr[i] = k;
	}

	sort(arr, arr + x);
	printf("%d", arr[y - 1]);
}