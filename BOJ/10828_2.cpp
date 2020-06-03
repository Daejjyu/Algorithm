#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	stack<int> st;

	for (int i = 0; i < N; i++)
	{
		string s; int d;
		cin >> s;
		if (s == "push") {
			cin >> d;
			st.push(d);
		} else if (s == "pop") {
			if (!st.empty()) {
				printf("%d\n", st.top()); st.pop();
			} else
				printf("-1\n");
		} else if (s == "size") {
			printf("%d\n", st.size());
		} else if (s == "empty") {
			printf("%d\n", (int)st.empty());
		} else if (s == "top") {
			if (!st.empty())
				printf("%d\n", st.top());
			else
				printf("-1\n");
		}
	}
}