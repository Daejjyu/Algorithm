#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int stick = 0, ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') {
			stick++;
		} else if (s[i] == ')') {
			stick--;
			if (s[i - 1] == ')')
				ans++;
			else
				ans += stick;
		}
	}
	printf("%d", ans);
}