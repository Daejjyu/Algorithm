#include<iostream>

int main()
{
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	for (int i = 1; i <= 15 * 28 * 19; i++)
	{
		int idx1 = (i % 15 > 0) ? i % 15 : 15;
		int idx2 = (i % 28 > 0) ? i % 28 : 28;
		int idx3 = (i % 19 > 0) ? i % 19 : 19;
		if (idx1 == E && idx2 == S && idx3 == M) {
			printf("%d", i);
			break;
		}
	}
}