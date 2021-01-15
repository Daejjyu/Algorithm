#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int const MAX = 20001;

vector<int> adjacent[MAX];
int visited[MAX];

int K, V, E;

void DFS(int idx, int color)
{
	visited[idx] = color;

	for (int i : adjacent[idx])
	{
		if (visited[i] == 0) {
			DFS(i, color*(-1));
		}
	}
}

int main(void)
{
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d", &V, &E);

		memset(visited, 0, sizeof(visited));
		bool twoGraph = true;
		for (int i = 1; i <= V; i++)
		{
			adjacent[i].clear();
		}

		while (E--) {
			int from, to;
			scanf("%d %d", &from, &to);
			adjacent[from].push_back(to);
			adjacent[to].push_back(from);
		}

		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0)
				DFS(i, 1);
		}

		for (int j = 1; j <= V; j++)
		{
			for (int i : adjacent[j])
			{
				if (visited[i] == visited[j])
					twoGraph = false;
			}
		}
		if (twoGraph)
			printf("YES\n");
		else
			printf("NO\n");
	}
}