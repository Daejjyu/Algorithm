#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int const MAX = 101;

vector<int> adjacent[MAX];
bool visited[MAX];
queue<int> q;

int n, startN, endN, cnt;

void BFS(int start, int end)
{
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			int idx = q.front();
			q.pop();
			for (int i : adjacent[idx])
			{
				if (i == end) {
					visited[i] = 1;
					return;
				}
				if (!visited[i]) {
					visited[i] = 1;
					q.push(i);
				}
			}
		}
		cnt++;
	}
}

int main(void)
{
	int d;
	scanf("%d %d %d %d", &n, &startN, &endN, &d);
	while (d--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	BFS(startN, endN);
	if (!visited[endN])
		printf("-1");
	else
		printf("%d", cnt + 1);
}