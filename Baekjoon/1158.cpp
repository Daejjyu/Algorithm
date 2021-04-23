#include <iostream>

const int MAX = 5000;
int arr[MAX];

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	int count = 0;
	int index = 0;
	int i = -1;
	printf("<");
	while (count < a) {
		i++;
		i %= a;
		if (arr[i] != -1) {
			index++;
			if (index == b) {
				index = 0;
				arr[i] = -1;
				count++;
				if (count == a)
					printf("%d", i + 1);
				else
					printf("%d, ", i + 1);
			}
		}
	}
	printf(">");
}