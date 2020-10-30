#include<iostream>
#include<string>
#include<stack>
using namespace std;

int arr[26];
int main()
{
	int N;
	scanf("%d", &N);
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}
	stack<double> st;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			st.push(arr[s[i] - 'A']);
		else {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			if (s[i] == '*')
				st.push(b * a);
			else if (s[i] == '/')
				st.push(b / a);
			else if (s[i] == '-')
				st.push(b - a);
			else if (s[i] == '+')
				st.push(b + a);
		}
	}
	printf("%.2f", st.top());
}