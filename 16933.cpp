#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[1000][1000];
bool possible = false;

queue<pair<pair<int, int>, pair<int, int>>> q;

int visited[1000][1000][11][3];
int N, M, K;
int ans;

int dR[4] = { 1,-1,0,0 };
int dC[4] = { 0,0,1,-1 };

void bfs()
{
	q.push({ {0, 0}, {0,1 } });
	visited[0][0][0][1] = 1;
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--)
		{
			int r = q.front().first.first;
			int c = q.front().first.second;
			int block = q.front().second.first;
			int day = q.front().second.second;
			q.pop();

			if (r == N - 1 && c == M - 1) {
				possible = true;
				return;
			}

			for (int i = 0; i < 4; i++)
			{
				int nextR = r + dR[i];
				int nextC = c + dC[i];
				if (nextR < 0 || nextC < 0 || N <= nextR || M <= nextC)
					continue;
				if (map[nextR][nextC] == 0 && !visited[nextR][nextC][block][3 - day]) {
					q.push({ {nextR,nextC},{block,3 - day} });
					visited[nextR][nextC][block][3 - day] = 1;
				} else if (block < K && map[nextR][nextC] == 1) {
					if (day == 2) {
						if (!visited[r][c][block][3 - day]) {
							q.push({ {r,c},{block,3 - day} });
							visited[r][c][block][3 - day] = 1;
						}
					} else if (!visited[nextR][nextC][block + 1][3 - day]) {
						q.push({ {nextR,nextC},{block + 1,3 - day} });
						visited[nextR][nextC][block + 1][3 - day] = 1;
					}
				}
			}
		}
		ans++;
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();

	if (possible)
		printf("%d", ans + 1);
	else
		printf("-1");
}