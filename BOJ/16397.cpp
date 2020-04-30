#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int visited[MAX];

int main(void)
{
	int N, T, G;
	scanf("%d %d %d", &N, &T, &G);

	queue<int> q;
	q.push(N);

	int t = -1;
	bool success = false;

	while (!success & !q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int pos = q.front();
			q.pop();

			if (pos == G) {
				success = true;
				break;
			}

			int buttonBNum;
			if (pos == 0)
				buttonBNum = 0;
			else {
				int firsitDigit = pos * 2;
				int digit = 1;
				while (firsitDigit >= 10) {
					firsitDigit /= 10;
					digit *= 10;
				}
				buttonBNum = pos * 2 - digit;
			}
			int nextP[2] = { pos + 1,buttonBNum };

			for (int i = 0; i < 2; i++)
			{
				int next = nextP[i];
				if (i == 1)
					if (pos * 2 > MAX - 1)
						continue;
				if (next < 0 || MAX - 1 < next)
					continue;
				if (visited[next])
					continue;
				visited[next]++;
				q.push(next);
			}
		}
		t++;
		if (t > T)
			break;
	}

	if (t < 0)
		t = 0;
	if (success && t <= T)
		printf("%d", t);
	else
		printf("ANG");
}