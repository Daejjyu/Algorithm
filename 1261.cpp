#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int ans;
priority_queue < pair< int, pair<int, int>>, vector < pair< int, pair<int, int>>>, greater < pair< int, pair<int, int>>>> q;

int dR[4] = { 1,-1,0,0 };
int dC[4] = { 0,0,1,-1 };

int bfs()
{
	q.push({ 0,{0,0} });
	visited[0][0] = 1;
	while (!q.empty()) {
		int block = q.top().first;
		int r = q.top().second.first;
		int c = q.top().second.second;
		q.pop();
		if (r == N - 1 && c == M - 1)
			return block;
		for (int i = 0; i < 4; i++)
		{
			int nextR = r + dR[i];
			int nextC = c + dC[i];
			if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
				continue;
			if (map[nextR][nextC] == 0 && !visited[nextR][nextC]) {
				q.push({ block, {nextR,nextC} });
				visited[nextR][nextC] = 1;
			} else if (map[nextR][nextC] == 1 && !visited[nextR][nextC]) {
				q.push({ block + 1,{nextR,nextC} });
				visited[nextR][nextC] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d", bfs());
}