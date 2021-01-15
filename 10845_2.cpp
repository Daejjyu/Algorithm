#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		string s; int d;
		cin >> s;
		if (s == "push") {
			cin >> d;
			q.push(d);
		} else if (s == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front()); q.pop();
			} else
				printf("-1\n");
		} else if (s == "size") {
			printf("%d\n", q.size());
		} else if (s == "empty") {
			printf("%d\n", (int)q.empty());
		} else if (s == "front") {
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("-1\n");
		} else if (s == "back") {
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
		}
	}
}