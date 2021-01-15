#include<iostream>
#include<string>
using namespace std;
const int mod = 1e6;
int dp[5001] = { 1,1 };

int main()
{
	string s;
	cin >> s;
	if (s[0] == 0) {
		printf("0");
		return 0;
	}

	for (int i = 2; i <= s.size(); i++)
	{
		if (s[i - 1] > '0')
			dp[i] = dp[i - 1];
		int x = stoi(s.substr(i - 2, 2));
		if (10 <= x && x <= 26)
			dp[i] += dp[i - 2];
		dp[i] %= mod;
	}
	printf("%d", dp[s.size()]);
}