#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 1001;
vector<int> adjacent[MAX];
bool visited[MAX];
queue<int> q;

void dfs(int idx)
{
	if (!visited[idx])
		printf("%d ", idx);
	visited[idx] = 1;
	for (int i : adjacent[idx])
	{
		if (!visited[i])
			dfs(i);
	}
}

void bfs(int idx)
{
	visited[idx] = 1;
	printf("%d ", idx);
	q.push(idx);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i : adjacent[cur])
		{
			if (!visited[i]) {
				q.push(i);
				printf("%d ", i);
				visited[i] = 1;
			}
		}
	}
}

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		adjacent[s].push_back(e);
		adjacent[e].push_back(s);
	}
	for (int i = 0; i < N; i++)
	{
		sort(adjacent[i].begin(), adjacent[i].end());
	}
	dfs(V);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	bfs(V);
}