#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
int visited[MAX];
int cnt;

queue<int> q;

int N, A, B, M;

void bfs(int start)
{
	q.push(start);
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			int cur = q.front();
			q.pop();
			for (int i : adj[cur])
			{
				if (!visited[i])
				{
					visited[i] = 1;
					q.push(i);
				}
				if (i == B) {
					return;
				}
			}
		}
		cnt++;
	}
}

int main()
{
	scanf("%d %d %d %d", &N, &A, &B, &M);
	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	bfs(A);
	if (!visited[B])
		printf("-1");
	else
		printf("%d", cnt + 1);
}