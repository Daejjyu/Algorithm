#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string W, S;
int dp[101][101];
vector<string> vec;

bool match(int w, int s)
{
	int &ret = dp[w][s];
	if (ret != -1)
		return ret;
	if (w < W.size() && s < S.size() && (W[w] == '?' || S[s] == W[w]))
		return ret = match(w + 1, s + 1);
	if (w == W.size())
		return ret = (s == S.size());
	if (W[w] == '*')
		return ret = match(w + 1, s) || (s < S.size() && match(w, s + 1));
	return ret = 0;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> W >> N;
		while (N--)
		{
			memset(dp, -1, sizeof(dp));
			cin >> S;

			if (match(0, 0))
				vec.push_back(S);
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << "\n";
		}
		vec.clear();
	}
}