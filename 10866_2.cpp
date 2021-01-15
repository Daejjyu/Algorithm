#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	deque<int> deq;

	for (int i = 0; i < N; i++)
	{
		string s; int d;
		cin >> s;
		if (s == "push_front") {
			cin >> d;
			deq.push_front(d);
		} else if (s == "push_back")
		{
			cin >> d;
			deq.push_back(d);
		} else if (s == "pop_front") {
			if (!deq.empty()) {
				printf("%d\n", deq.front()); deq.pop_front();
			} else
				printf("-1\n");
		} else if (s == "pop_back") {
			if (!deq.empty()) {
				printf("%d\n", deq.back()); deq.pop_back();
			} else
				printf("-1\n");
		} else if (s == "size") {
			printf("%d\n", deq.size());
		} else if (s == "empty") {
			printf("%d\n", (int)deq.empty());
		} else if (s == "front") {
			if (!deq.empty())
				printf("%d\n", deq.front());
			else
				printf("-1\n");
		} else if (s == "back") {
			if (!deq.empty())
				printf("%d\n", deq.back());
			else
				printf("-1\n");
		}
	}
}