#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string str;

	while (n--)
	{
		cin >> str;
		vector<int> arr;
		bool ans = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				arr.push_back(1);
			else if (str[i] == ')') {
				if (arr.empty()) {
					cout << "NO" << "\n";
					ans = true;
					break;
				} else arr.pop_back();
			}
		}
		if (ans)
			continue;
		if (arr.empty())
			cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}