#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int visited[10000];

string bfs(int A, int B)
{
	queue<pair<int, string>> q;
	q.push({ A, "" });
	visited[A] = 1;
	while (!q.empty()) {
		int num = q.front().first;
		string sudo = q.front().second;

		q.pop();

		if (num == B)
			return sudo;

		int D = num * 2 % 10000;
		if (!visited[D]) {
			q.push({ D,sudo + "D" });
			visited[D] = 1;
		}

		int S = (num - 1 < 0) ? 9999 : num - 1;
		if (!visited[S]) {
			q.push({ S,sudo + "S" });
			visited[S] = 1;
		}
		int L = num % 1000 * 10 + num / 1000;
		if (!visited[L]) {
			q.push({ L,sudo + "L" });
			visited[L] = 1;
		}
		int R = num / 10 + num % 10 * 1000;
		if (!visited[R]) {
			q.push({ R,sudo + "R" });
			visited[R] = 1;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(visited, false, sizeof(visited));
		int A, B;
		cin >> A >> B;
		cout << bfs(A, B) << "\n";
	}
}