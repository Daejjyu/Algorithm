#include <iostream>

int const MAX = 101;

int arr[MAX][MAX];
int visited[MAX][MAX];

int n;

void DFS(int num, int start, int end)
{
	visited[num][end] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[end][i] && !visited[num][i])
			DFS(num, end, i);
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] && !visited[i][j]) {
				DFS(i, i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}