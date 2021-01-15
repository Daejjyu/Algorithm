#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[1001];
vector<int> adjacent[1001];
int T, N, M;

void dfs(int idx, int color)
{
	visited[idx] = color;
	for (int i = 0; i < adjacent[idx].size(); i++)
	{
		if (!visited[adjacent[idx][i]])
			dfs(adjacent[idx][i], 3 - color);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &M);
		memset(visited, 0, sizeof(visited));
		memset(adjacent, 0, sizeof(adjacent));

		for (int i = 0; i < M; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			adjacent[x].push_back(y);
			adjacent[y].push_back(x);
		}
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
				dfs(i, 1);
		}
		bool flag = true;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < adjacent[i].size(); j++)
			{
				if (visited[i] == visited[adjacent[i][j]]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag)
			printf("possible\n");
		else
			printf("impossible\n");
	}
}