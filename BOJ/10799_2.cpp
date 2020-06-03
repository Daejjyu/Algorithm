#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int stick = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			stick++;
		else {
			stick--;
			if (s[i - 1] == ')')
				ans += 1;
			else ans += stick;
		}
	}
	cout << ans;
}