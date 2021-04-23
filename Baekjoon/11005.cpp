#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int bub;
	cin >> str >> bub;

	long long sum = 0;

	for (int i = 0; i < str.size(); i++)
	{
		int nn;
		if ('A' <= str[i])
			nn = str[i] - 'A' + 10;
		else
			nn = str[i] - '0';
		sum *= bub;
		sum += nn;
	}

	cout << sum;
}