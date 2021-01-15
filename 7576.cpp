#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int const MAX = 1001;

int box[MAX][MAX];
queue<pair<int, int>> tomato;
int XY[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int m, n, day;

void BFS()
{
	while (!tomato.empty()) {
		int curSize = tomato.size();
		while (curSize--) {
			int x = tomato.front().first;
			int y = tomato.front().second;
			tomato.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextX = x + XY[i][0];
				int nextY = y + XY[i][1];
				if (1 <= nextX && nextX <= m && 1 <= nextY && nextY <= n)
					if (box[nextX][nextY] == 0) {
						box[nextX][nextY] = 1;
						pair<int, int> b;
						b.first = nextX;
						b.second = nextY;
						tomato.push(b);
					}
			}
		}
		day++;
	}
}

int main(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &box[j][i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (box[j][i] == 1) {
				pair<int, int> a;
				a.first = j;
				a.second = i;
				tomato.push(a);
			}
		}
	}

	BFS();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (box[j][i] == 0) {
				day = 0;
				break;
			}
		}
	}
	printf("%d", day - 1);
}