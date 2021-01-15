#include <iostream>

int main()
{
	int N;
	scanf("%d", &N);

	while (N > 1) {
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0) {
				printf("%d\n", i);
				N /= i;
				break;
			}
		}
	}
}