#include <iostream>

int const MAX = 1000;

int adjacent[MAX][MAX];
int visited[MAX];

int N, M;
int count;

void DFS(int idx)
{
	visited[idx] = 1;

	for (int i = 1; i <= MAX; i++)
	{
		if (!visited[i] && adjacent[idx][i])
			DFS(i);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	while (M--) {
		int from, to;
		scanf("%d %d", &from, &to);
		adjacent[from][to] = 1;
		adjacent[to][from] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i]) {
			DFS(i);
			count++;
		}
	}

	printf("%d", count);
}