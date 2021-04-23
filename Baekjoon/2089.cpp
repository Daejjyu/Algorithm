#include <iostream>

int arr[35];

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 0)
		printf("0");

	int count = 0;
	int evenDigit = 0;
	int Digit;

	while (n != 0) {
		if (n < 0) {
			n = n * (-1);
			if (n % 2 == 0) {
				arr[count++] = 0;
				n = n / 2;
			} else {
				arr[count++] = 1;
				n = n / 2 + 1;
			}
		} else {
			if (n % 2 == 0)
				arr[count++] = 0;
			else
				arr[count++] = 1;
			n = (n / 2)*(-1);
		}
	}
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", arr[i]);
		printf("%d", count);
	}
}