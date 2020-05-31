#include <iostream>

int main()
{
	char C;
	int num = 0;
	while (~scanf("%1c", &C)) {
		num++;
		printf("%c", C);
		if (num == 10) {
			printf("\n");
			num = 0;
		}
	}
}