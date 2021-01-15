#include<iostream>
#include<cstring>
using namespace std;

int arr[26];
int main()
{
	memset(arr, -1, sizeof(arr));
	char c;
	int i = 0;
	while (~scanf("%c", &c)) {
		int d = c - 'a';
		if (arr[d] == -1)
			arr[d] = i;
		i++;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
}