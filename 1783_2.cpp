#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	if (R == 1) {
		printf("%d", 1);
	} else if (R == 2) {
		printf("%d", min(1 + (C - 1) / 2, 4));
	} else {
		if (C <= 4)
			printf("%d", C);
		else
			printf("%d", max(4, C - 2));
	}
}