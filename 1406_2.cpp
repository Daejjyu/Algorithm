#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

string s;
list<char> arr;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		arr.push_back(s[i]);
	}

	int N;
	cin >> N;
	list<char>::iterator cursor = arr.end();
	char sudo;
	for (int i = 0; i < N; i++)
	{
		cin >> sudo;
		if (sudo == 'L') {
			if (cursor != arr.begin())
				cursor--;
		} else if (sudo == 'D')
		{
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

	for (list<char>::iterator i = arr.begin(); i != arr.end(); i++)
	{
		cout << *i;
	}
}