#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	cin >> str;
	int sum = 0;
	bool success = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
			success = true;
		sum += str[i] - '0';
	}
	if (sum % 3 != 0 || !success)
		printf("-1");
	else {
		sort(str.begin(), str.end(), cmp);
		cout << str;
	}
}