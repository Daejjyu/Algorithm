#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string s;

	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			s[i] = (((s[i] - 'a') + 13) % 26) + 'a';
		}
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] = (((s[i] - 'A') + 13) % 26) + 'A';
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		cout << s;
	}
}