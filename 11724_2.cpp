#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int idx)
{
	visited[idx] = 1;
	for (int i : adj[idx])
	{
		if (!visited[i])
			dfs(i);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	printf("%d", ans);
}