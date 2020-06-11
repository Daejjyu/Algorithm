#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
int visited[100000];

bool possible = false;
int ans = 0;

int N, T, G;
void bfs(int start)
{
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			int cur = q.front();
			q.pop();

			if (cur == G) {
				possible = true;
				return;
			}

			int next1 = cur + 1;
			if (next1 <= 99999) {
				if (!visited[next1]) {
					q.push(next1);
					visited[next1] = 1;
				}
			}
			int next2 = cur * 2;

			if (next2 != 0 && next2 <= 99999) {
				string s = to_string(next2);
				s[0] -= 1;
				next2 = stoi(s);
				if (!visited[next2]) {
					q.push(next2);
					visited[next2] = 1;
				}
			}
		}
		ans++;
		if (ans > T)
			return;
	}
}

int main()
{
	scanf("%d %d %d", &N, &T, &G);

	bfs(N);

	if (possible)
		printf("%d", ans);
	else
		printf("ANG");
}