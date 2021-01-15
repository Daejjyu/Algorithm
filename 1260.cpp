#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1001;

int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx)
{
	cout << idx << " ";

	for (int i = 1; i <= N; i++)
	{
		if (adjacent[idx][i] && !visited[i]) {
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int idx)
{
	q.push(idx);
	visited[idx] = 1;

	while (!q.empty())
	{
		idx = q.front();
		cout << idx << " ";
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (adjacent[idx][i] == 1 && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M >> V;
	int from, to;
	while (M--) {
		cin >> from >> to;
		adjacent[from][to] = 1;
		adjacent[to][from] = 1;
	}
	visited[V] = 1;
	DFS(V);
	cout << "\n";

	memset(visited, 0, sizeof(visited));
	BFS(V);
}