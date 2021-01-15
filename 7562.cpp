#include <iostream>
#include <queue>
using namespace std;

int dy[8] = { -1,-2,-2,-1,1,2,1,2 };
int dx[8] = { -2,-1,1,2,-2,-1,2,1 };

int main(void)
{
	int T, L;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &L);
		int map[300][300] = { 0 };
		queue<int> q;

		int x1, y1, x2, y2;
		int cnt = 0;
		bool success = false;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		q.push(300 * x1 + y1);
		map[x1][y1] = 1;

		while (!q.empty()) {
			if (success)
				break;
			int qSize = q.size();
			printf("큐사이즈 %d \n", qSize);

			while (qSize--) {
				int x = q.front() / 300;
				int y = q.front() % 300;
				q.pop();
				printf("x y %d %d \n", x, y);
				if (x == x2 && y == y2) {
					success = true;
					break;
				}
				for (int i = 0; i < 8; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (ny < 0 || ny >= L || nx < 0 || nx >= L)
						continue;
					if (map[nx][ny])
						continue;
					printf("돈다 %d %d\n", nx, ny);
					q.push(nx * 300 + ny);
					map[nx][ny]++;
				}
			}
			cnt++;
		}

		printf("%d\n", cnt);
	}
}