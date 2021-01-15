#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int R, C;
	scanf("%d %d", &R, &C);

	const int MAX = 51;

	queue<int> q;
	queue<int> wQ;

	int visited[MAX][MAX] = { 0 };
	char map[MAX][MAX];

	char ch;

	for (int i = 1; i <= R; i++)
	{
		scanf("%c", &ch);
		for (int j = 1; j <= C; j++)
		{
			scanf("%c", &ch);
			if (ch == '*')
			{
				wQ.push(j*MAX + i);
			}
			if (ch == 'S') {
				q.push(j*MAX + i);
				ch = '.';
				visited[j][i] = 1;
			}
			map[j][i] = ch;
		}
	}

	bool success = false;
	int cnt = 0;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!q.empty() && !success) {
		int qSize = q.size();
		while (qSize--) {
			int posX = q.front() / MAX;
			int posY = q.front() % MAX;
			q.pop();

			if (map[posX][posY] == '*')
				continue;
			for (int i = 0; i < 4; i++)
			{
				int nextX = posX + dx[i];
				int nextY = posY + dy[i];

				if (map[nextX][nextY] == 'D')
				{
					success = true;
					break;
				}

				if (nextX < 1 || C < nextX || nextY < 1 || R < nextY)
					continue;
				else if (map[nextX][nextY] == '.' && !visited[nextX][nextY])
				{
					visited[nextX][nextY] = 1;
					q.push(nextX*MAX + nextY);
				}
			}
		}
		if (success)
			break;

		int wQSize = wQ.size();
		while (wQSize--) {
			int posX = wQ.front() / MAX;
			int posY = wQ.front() % MAX;
			wQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextX = posX + dx[i];
				int nextY = posY + dy[i];

				if (nextX < 1 || C < nextX || nextY < 1 || R < nextY)
					continue;
				else if (map[nextX][nextY] == '.')
				{
					map[nextX][nextY] = '*';
					wQ.push(nextX*MAX + nextY);
				}
			}
		}
		cnt++;
	}

	if (success)
		printf("%d", cnt + 1);
	else
		printf("KAKTUS");
}