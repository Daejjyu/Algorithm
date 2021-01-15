#include <iostream>
#include <queue>
using namespace std;

int visited[1000001] = { 0 };

int main(void)
{
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	queue<int> q;
	q.push(S);

	int cnt = 0;
	bool success = false;

	while (!success && !q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int pos = q.front();
			q.pop();

			if (pos == G) {
				success = true;
				break;
			}
			int nUp = pos + U;
			int nDown = pos - D;

			if (1 <= nUp && nUp <= F)
				if (!visited[nUp]) {
					visited[nUp]++;
					q.push(nUp);
				}
			if (1 <= nDown && nDown <= F)
				if (!visited[nDown]) {
					visited[nDown]++;
					q.push(nDown);
				}
		}
		cnt++;
	}
	if (success)
		printf("%d", cnt - 1);
	else
		printf("use the stairs");
}