#include<iostream>
#include<cstring>
using namespace std;

int adj[100][100];
int visited[100];

int N;

void dfs(int r, int c)
{
	visited[c] = 1;
	for (int j = 0; j < N; j++)
	{
		if (adj[c][j] == 1 && !visited[j])
			dfs(c, j);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &adj[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j] == 1)
				dfs(i, j);
		}

		for (int j = 0; j < N; j++)
		{
			printf("%d ", visited[j]);
		}
		printf("\n");
	}
}