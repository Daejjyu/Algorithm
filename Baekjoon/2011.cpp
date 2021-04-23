#include <iostream>
#include <string>
using namespace std;

int dp[5001];
#define mod 1000000;

int main()
{
	string s;
	cin >> s;

	if (s[0] == '0')
	{
		printf("0");
		return 1;
	}

	dp[0] = dp[1] = 1;

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] > '0')
			dp[i + 1] = dp[i];

		int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			dp[i + 1] += dp[i - 1];
		}
		dp[i + 1] %= mod;
	}
	printf("%d", dp[s.length()]);
}

//반례 : 1203 -> 1개