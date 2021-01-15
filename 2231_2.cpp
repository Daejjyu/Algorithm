#include<iostream>

int N;

int main()
{
	scanf("%d", &N);

	bool possible = false;
	for (int i = 1; i <= 1000000; i++)
	{
		int tmp = i, lap = i;
		while (lap) {
			tmp += lap % 10;
			lap /= 10;
		}
		if (tmp == N) {
			possible = true;
			printf("%d", i);
			break;
		}
	}
	if (!possible)
		printf("0");
}