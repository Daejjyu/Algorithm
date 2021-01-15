#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	const int MAX = 100000;

	int visited[MAX + 1] = { 0 };

	queue<int> q;
	q.push(N);

	int time = 0;
	int success = false;

	while (!success && !q.empty())
	{
		int qSize = q.size();
		while (qSize--) {
			int pos = q.front();
			q.pop();

			if (pos == K)
			{
				success = true;
				break;
			}
			int nextPos[3] = { pos - 1, pos + 1, pos * 2 };

			for (int i = 0; i < 3; i++)
			{
				int next = nextPos[i];
				if (next < 0 || MAX < next)
					continue;
				if (visited[next])
					continue;
				visited[next]++;
				q.push(next);
			}
		}
		time++;
	}
	printf("%d", time - 1);
}