#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	while (N--) {
		stack<char> st;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')')
			{
				if (st.empty()) {
					st.push(')');
					break;
				}
				if (st.top() == '(')
					st.pop();
				else
					st.push(')');
			} else
				st.push('(');
		}
		if (st.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
}