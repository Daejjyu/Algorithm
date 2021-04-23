#include <iostream>
#include <algorithm>
using namespace std;

int const MAX = 25 + 1;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int n, bigCnt;
int smallCnt[313];

void DFS(int x, int y)
{
	visited[x][y] = 1;
	if (arr[x][y] == 1) {
		smallCnt[bigCnt]++;
		if (x + 1 <= n && !visited[x + 1][y]) DFS(x + 1, y);
		if (x - 1 >= 1 && !visited[x - 1][y]) DFS(x - 1, y);
		if (y + 1 <= n && !visited[x][y + 1]) DFS(x, y + 1);
		if (y - 1 >= 1 && !visited[x][y - 1]) DFS(x, y - 1);
	}
}

int main(void)
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int d;
			scanf("%1d", &d);
			arr[i][j] = d;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 0)
				visited[i][j] = 1;
			else if (!visited[i][j]) {
				DFS(i, j);
				bigCnt++;
			}
		}
	}
	sort(smallCnt, smallCnt + bigCnt);
	printf("%d\n", bigCnt);
	for (int i = 0; i < bigCnt; i++)
	{
		printf("%d\n", smallCnt[i]);
	}
}