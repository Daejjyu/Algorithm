#include<iostream>

int main(void)
{
	int d;
	scanf("%d", &d);
	if (d == 0)
		printf("1");
	else {
		int fact = d--;
		while (d > 0) {
			fact *= d;
			d--;
		}
		printf("%d", fact);
	}
}