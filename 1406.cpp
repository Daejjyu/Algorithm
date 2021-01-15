#include<iostream>
#include <list>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; int n;
	cin >> s >> n;

	list<char> arr;

	for (int i = 0; i < s.size(); i++)
	{
		arr.push_back(s[i]);
	}

	char sudo;
	list<char>::iterator cursor = arr.end();
	while (n--) {
		cin >> sudo;
		if (sudo == 'L') {
			if (cursor != arr.begin())
				cursor--;
		} else if (sudo == 'D') {
			if (cursor != arr.end())
				cursor++;
		} else if (sudo == 'B') {
			if (cursor != arr.begin())
				cursor = arr.erase(--cursor);
		} else if (sudo == 'P') {
			cin >> sudo;
			arr.insert(cursor, sudo);
		}
	}
	for (std::list<char>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it;
	}
}