#include <iostream>

int main()
{
	int T;
	scanf("%d", &T);
	int N = 1;
	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", N, A + B);
		N++;
	}
}