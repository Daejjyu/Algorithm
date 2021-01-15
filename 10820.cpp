#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (getline(cin, s)) {
		int small = 0, big = 0, nNum = 0, nSpace = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
				nNum++;
			else if ('A' <= s[i] && s[i] <= 'Z')
				big++;
			else if ('a' <= s[i] && s[i] <= 'z')
				small++;
			else if (s[i] == ' ')
				nSpace++;
		}
		cout << small << " " << big << " " << nNum << " " << nSpace << "\n";
	}
}