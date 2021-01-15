#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
long long maxDist;
long long high, low;
long long mid;

int house[200000];

bool compare(int mid)
{
	long long tempHouse = house[0];
	int temp = 1;
	for (int i = 1; i < N; i++)
	{
		if (tempHouse + mid <= house[i]) {
			temp++;
			tempHouse = house[i];
		}
	}
	if (temp >= C)
		return true;
	else
		return false;
}

int main(void)

{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &house[i]);
		if (high < house[i])
			high = house[i];
	}

	sort(house, house + N);
	low = 1;

	while (low <= high) {
		mid = low + (high - low) / 2;
		if (compare(mid)) {
			if (maxDist < mid)
				maxDist = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	printf("%lld", maxDist);
}