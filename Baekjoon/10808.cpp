#include <iostream>

int arr[26];

int main(void)
{
	char c;
	while (~scanf("%c", &c)) {
		int a = c - 'a';
		arr[a]++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
}