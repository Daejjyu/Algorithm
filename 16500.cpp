#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string S;
int N;
vector<string> vec;
int dp[100];

bool match(int idx)
{
	if (idx == S.length())
		return 1;

	if (dp[idx] != -1)
		return dp[idx];

	dp[idx] = 0;

	for (int i = 0; i < N; i++)
	{
		if (S.length() < vec[i].length() + idx)
			continue;

		bool flag = true;

		for (int j = 0; j < vec[i].length(); j++)
		{
			if (S[idx + j] != vec[i][j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			dp[idx] |= match(idx + vec[i].length());
		}
	}

	return dp[idx];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	memset(dp, -1, sizeof(dp));

	cout << match(0) << "\n";

	return 0;
}