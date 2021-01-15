#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1001;
int visited[MAX];
int adj[MAX];
int ans;

void dfs(int idx)
{
	visited[idx] = 1;

	if (visited[adj[idx]] == 0)
		dfs(adj[idx]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
		ans = 0;

		for (int i = 1; i <= N; i++)
		{
			int d;
			scanf("%d", &d);
			adj[i] = d;
		}

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i]) {
				dfs(i);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}