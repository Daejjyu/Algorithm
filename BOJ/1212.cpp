#include <iostream>

int arrFirst[8] = { 0, 1,10,11,100,101,110,111 };
char arr[8][4] = { "000", "001","010","011","100","101","110","111" };

int main(void)
{
	int n;
	scanf("%1d", &n);
	printf("%d", arrFirst[n]);
	while (~scanf("%1d", &n)) {
		printf("%s", arr[n]);
	}
}