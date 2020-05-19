#include <iostream>

int main()
{
	int min = 1e8;
	int N;
	scanf("%d", &N);
	for (int i = 10; i < 1000001; i++)
	{
		int sum = 0;
		sum += i;
		int idx = i;
		while (idx) {
			sum += idx % 10;
			idx /= 10;
		}
		if (sum == N && i < min)
			min = i;
	}
	if (min != 1e8)
		printf("%d", min);
	else
		printf("%d", 0);
}