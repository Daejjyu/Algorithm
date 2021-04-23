#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1000;
char map[MAX][MAX];
int visited[MAX][MAX];

queue<int> q;
queue<int> fQ;

bool possible = false;
int time;
int C, R;

int nR[4] = { 0,0,1,-1 };
int nC[4] = { 1,-1,0,0 };

void bfs()
{
	//move
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			int r = q.front() / 1001;
			int c = q.front() % 1001;
			q.pop();

			if (map[r][c] == '*')
				continue;

			for (int i = 0; i < 4; i++)
			{
				int nextR = r + nR[i];
				int nextC = c + nC[i];

				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) {
					possible = true;
					return;
				} else {
					if (map[nextR][nextC] == '.' && !visited[nextR][nextC]) {
						q.push(nextR * 1001 + nextC);
						visited[nextR][nextC] = 1;
					}
				}
			}
		}

		//fire
		curSize = fQ.size();
		while (curSize--) {
			int r = fQ.front() / 1001;
			int c = fQ.front() % 1001;
			fQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextR = r + nR[i];
				int nextC = c + nC[i];
				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C)
					continue;
				if (map[nextR][nextC] == '.') {
					map[nextR][nextC] = '*';
					fQ.push(nextR * 1001 + nextC);
				}
			}
		}

		time++;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &C, &R);

		memset(visited, 0, sizeof(visited));
		possible = false;
		time = 1;
		while (!q.empty())
			q.pop();
		while (!fQ.empty())
			fQ.pop();

		for (int i = 0; i < R; i++)
		{
			char c;
			scanf("%c", &c);
			for (int j = 0; j < C; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@') {
					q.push(i * 1001 + j);
					visited[i][j] = 1;
				} else if (map[i][j] == '*')
					fQ.push(i * 1001 + j);
			}
		}

		bfs();

		if (possible)
			printf("%d\n", time);
		else
			printf("IMPOSSIBLE\n");
	}
}