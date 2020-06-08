#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 20001;
vector<int> adj[MAX];
int visited[MAX];
int V, E;

void dfs(int idx, int color)
{
	visited[idx] = color;
	for (int j : adj[idx])
	{
		if (!visited[j])
			dfs(j, 3 - color);
	}
}

int main()
{
	int K;
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d", &V, &E);

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < MAX; i++)
		{
			adj[i].clear();
		}

		for (int i = 0; i < E; i++)
		{
			int s, e;
			scanf("%d %d", &s, &e);
			adj[s].push_back(e);
			adj[e].push_back(s);
		}

		for (int i = 1; i <= V; i++)
		{
			if (!visited[i])
				dfs(i, 1);
		}
		bool possible = true;
		for (int i = 1; i <= V; i++)
		{
			for (int j : adj[i])
			{
				if (visited[i] == visited[j]) {
					possible = false;
					break;
				}
			}
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
}