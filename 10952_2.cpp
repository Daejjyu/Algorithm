#include <iostream>

int main()
{
	int A, B;
	while (~scanf("%d %d", &A, &B)) {
		if (A == 0 && B == 0)
			break;
		printf("%d\n", A + B);
	}
}