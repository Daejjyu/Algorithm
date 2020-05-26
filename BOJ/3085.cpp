#include<iostream>
#include<algorithm>
using namespace std;

char arr[50][50];
int N;
int ans;

void calculate()
{
	int temp = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1]) {
				temp++;
				if (temp > ans)
					ans = temp;
			} else
				temp = 1;
		}
		temp = 1;
	}

	temp = 1;
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i + 1][j] == arr[i][j]) {
				temp++;
				if (temp > ans)
					ans = temp;
			} else
				temp = 1;
		}
		temp = 1;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char c;
		scanf("%c", &c);
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j + 1 < N) {
				swap(arr[i][j], arr[i][j + 1]);
				calculate();
				swap(arr[i][j], arr[i][j + 1]);
			}

			if (i + 1 < N) {
				swap(arr[i][j], arr[i + 1][j]);
				calculate();
				swap(arr[i][j], arr[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
}