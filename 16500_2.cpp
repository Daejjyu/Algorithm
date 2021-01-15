#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int N, dp[101];
vector<string> vec;
string s;

bool possible(int idx)
{
	int &ret = dp[idx];
	if (ret != -1)
		return ret;
	if (idx == s.size())
		return 1;
	ret = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (idx + vec[i].size() > s.size())
			continue;

		bool flag = true;
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (s[idx + j] != vec[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			ret |= possible(idx + vec[i].size());
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> s >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}

	cout << possible(0);
}