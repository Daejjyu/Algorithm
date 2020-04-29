#include <iostream>

const int MAX = 100001;

int need[MAX];
int visited[MAX];
int finished[MAX];

int t, n, cnt;

void DFS(int idx)
{
	visited[idx] = 1;
	int nextIdx = need[idx];
	if (!visited[nextIdx])
		DFS(nextIdx);
	else if (!finished[nextIdx])
	{
		for (int i = nextIdx; i != idx; i = need[i])
		{
			cnt++;
		}
		cnt++;
	}
	finished[idx] = 1;
}

int main(void)
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			visited[i] = 0;
			finished[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &need[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				DFS(i);
		}
		printf("%d\n", n - cnt);
	}
}