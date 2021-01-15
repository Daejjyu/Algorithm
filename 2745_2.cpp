#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> arr;

int main()
{
	string N; int B;
	cin >> N >> B;

	int ans = 0;
	for (int i = 0; i < N.size(); i++)
	{
		ans *= B;
		int num;
		if ('A' <= N[i] && N[i] <= 'Z')
			num = N[i] - 'A' + 10;
		else
			num = N[i] - '0';
		ans += num;
	}
	printf("%d", ans);
}