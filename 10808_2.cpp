#include<iostream>

int arr[26];
int main()
{
	char c;
	while (~scanf("%c", &c)) {
		int d = c - 'a';
		arr[d]++;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
}