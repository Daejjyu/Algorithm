#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
int adj[MAX];
bool visited[MAX];
bool finished[MAX];
int cnt;

void dfs(int idx)
{
	visited[idx] = 1;
	int next = adj[idx];

	if (!visited[next])
		dfs(next);
	else if (!finished[next]) {
		for (int i = next; i != idx; i = adj[i])
		{
			cnt++;
		}
		cnt++;
	}
	finished[idx] = 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		cnt = 0;
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		memset(adj, 0, sizeof(adj));

		for (int i = 1; i <= N; i++)
		{
			int d;
			scanf("%d", &d);
			adj[i] = d;
		}

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
				dfs(i);
		}

		printf("%d\n", N - cnt);
	}
}