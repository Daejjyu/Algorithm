#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dp[101];
string S;
vector<string> vec;
int N;

bool match(int idx)
{
	int &ret = dp[idx];
	if (ret != -1)
		return ret;
	if (idx == S.length())
		return ret = 1;

	ret = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		bool flag = true;
		if (idx + vec[i].length() > S.length())
			continue;
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (S[idx + j] != vec[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			ret |= match(idx + vec[i].length());
	}
	return ret;
}
int main()
{
	cin >> S >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}
	memset(dp, -1, sizeof(dp));

	cout << match(0) ? 1 : 0;
}