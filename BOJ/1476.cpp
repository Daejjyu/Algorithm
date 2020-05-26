#include <iostream>

int E, S, M;

int main()
{
	scanf("%d %d %d", &E, &S, &M);
	int input[3] = { E,S,M };
	int num[3];
	int ESM[3] = { 15,28,19 };
	int ans = 0;

	for (int i = 1; i <= 15 * 28 * 19; i++)
	{
		bool flag = true;
		for (int j = 0; j < 3; j++)
		{
			num[j] = i % ESM[j];
			if (num[j] == 0)
				num[j] = ESM[j];
			if (num[j] != input[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
}