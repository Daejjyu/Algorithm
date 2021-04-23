#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;

vector<int> adjacent[MAX];
int visited[MAX];

int t, n;

void DFS(int idx)
{
	visited[idx] = 1;

	for (int i : adjacent[idx])
	{
		if (!visited[i])
			DFS(i);
	}
}

int main(void)
{
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		memset(visited, 0, sizeof(visited));
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			adjacent[i].clear();
		}

		for (int i = 1; i <= n; i++)
		{
			int d;
			scanf("%d", &d);
			adjacent[i].push_back(d);
			adjacent[d].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				DFS(i);
				count++;
			}
		}
		printf("%d\n", count);
	}
}