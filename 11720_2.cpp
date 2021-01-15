#include <iostream>

int main()
{
	int D;
	int sum = 0;
	scanf("%d", &D);
	while (~scanf("%1d", &D)) {
		sum += D;
	}
	printf("%d", sum);
}