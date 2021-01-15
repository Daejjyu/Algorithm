#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
const int MAX = 1000;
int map[MAX][MAX];

int cnt;

int nR[4] = { 0,0,1,-1 };
int nC[4] = { -1,1,0,0 };
int R, C;

void bfs()
{
	bool end = false;
	while (!end && !q.empty()) {
		int num = q.size();
		while (!end && num--) {
			int curR = q.front() / 1001;
			int curC = q.front() % 1001;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextR = curR + nR[i];
				int nextC = curC + nC[i];
				if (nextR < 0 || nextC < 0 || R <= nextR || C <= nextC)
					continue;
				if (map[nextR][nextC] == 1) {
					if (nextR == R - 1 && nextC == C - 1) {
						end = true;
						break;
					}
					map[nextR][nextC] = 0;
					q.push(1001 * nextR + nextC);
				}
			}
		}
		cnt++;
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	q.push(0);
	bfs();

	printf("%d", cnt + 1);
}