#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int, int> visited;
queue<int> q;

int a, p;

void BFS(int idx)
{
	q.push(idx);
	int firstLap = 1;
	int secondLap = 0;
	visited[idx]++;

	while (!q.empty()) {
		idx = q.front();
		q.pop();

		int sum = 0;
		while (idx) {
			int value = idx % 10;
			int lap = p;
			int mul = 1;
			while (lap--) {
				mul *= value;
			}
			sum += mul;
			idx /= 10;
		}
		if (!visited[sum]) {
			visited[sum]++;
			q.push(sum);
			firstLap++;
		} else if (visited[sum] < 2)
		{
			visited[sum]++;
			q.push(sum);
			secondLap++;
		} else {
			printf("%d", firstLap - secondLap);
			break;
		}
	}
}

int main(void)
{
	scanf("%d %d", &a, &p);
	BFS(a);
}