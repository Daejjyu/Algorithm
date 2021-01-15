#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[4];
int main()
{
	char c;
	while (~scanf("%c", &c)) {
		if ('a' <= c && c <= 'z')
			arr[0]++;
		else if ('A' <= c && c <= 'Z')
			arr[1]++;
		else if ('0' <= c && c <= '9')
			arr[2]++;
		else if (c == ' ')
			arr[3]++;
		else if (c == '\n') {
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
			memset(arr, 0, sizeof(arr));
		}
	}
}