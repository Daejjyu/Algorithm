#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int stick = 0, ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			stick++;
		} else {
			stick--;
			if (str[i - 1] == '(')
				ans += stick;
			else
				ans++;
		}
	}
	cout << ans;
}