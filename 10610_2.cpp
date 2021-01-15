#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool possible = false;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
			possible = true;
		sum += s[i] - '0';
	}
	sort(s.begin(), s.end(), greater<char>());

	if (possible&&sum % 3 == 0)
		cout << s;
	else
		cout << -1;
}