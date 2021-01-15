#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			printf("%c", s[i]);
		else {
			switch (s[i]) {
				case '(':
					st.push(s[i]);
					break;
				case '*':
				case '/':
					while (!st.empty() && (st.top() == '/' || st.top() == '*')) {
						printf("%c", st.top());
						st.pop();
					}
					st.push(s[i]);
					break;
				case '+':
				case '-':
					while (!st.empty() && st.top() != '(') {
						printf("%c", st.top());
						st.pop();
					}
					st.push(s[i]);
					break;
				case ')':
					while (!st.empty() && st.top() != '(') {
						printf("%c", st.top());
						st.pop();
					}
					st.pop();
					break;
			}
		}
	}
	while (!st.empty())
	{
		printf("%c", st.top());
		st.pop();
	}
}