#include <iostream>
#include <cstring>

int main(void)
{
	char c;
	int cnt = 0;
	int arr[26];
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
	while (~scanf("%c", &c)) {
		int idx = c - 'a';
		if (arr[idx] == -1)
			arr[idx] = cnt;
		cnt++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
}