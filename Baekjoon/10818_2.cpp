#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int ansMin = 1e9, ansMax = -1e9;
	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		ansMin = min(ansMin, d);
		ansMax = max(ansMax, d);
	}
	printf("%d %d", ansMin, ansMax);
}