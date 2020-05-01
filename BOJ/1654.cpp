#include <iostream>
#include <algorithm>
using namespace std;

int K, N;

int lanNum[10001];

bool search(int mid)
{
	int temp = 0;
	for (int i = 1; i <= K; i++)
	{
		temp += lanNum[i] / mid;
	}
	if (temp >= N)
		return true;
	else
		return false;
}

int main(void)
{
	scanf("%d %d", &K, &N);

	long long  low = 1;
	long long  high = 0;
	long long mid = 0;

	for (int i = 1; i <= K; i++)
	{
		scanf("%d", &lanNum[i]);
		if (lanNum[i] > high)
			high = lanNum[i];
	}

	int maxLength = 0;

	while (low <= high) {
		mid = low + (high - low) / 2;
		if (search(mid)) {
			if (maxLength < mid)
				maxLength = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	printf("%d", maxLength);
}