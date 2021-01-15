#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[50];
int N, M;

string wFirst[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

string bFirst[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int ans = 1e8;

	for (int idx1 = 0; idx1 + 8 <= N; idx1++)
	{
		for (int idx2 = 0; idx2 + 8 <= M; idx2++)
		{
			int ans1 = 0;
			int ans2 = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (arr[idx1 + i][idx2 + j] != bFirst[i][j])
						ans1++;
					if (arr[idx1 + i][idx2 + j] != wFirst[i][j])
						ans2++;
				}
			}
			ans = min(ans, ans1);
			ans = min(ans, ans2);
		}
	}
	cout << ans;
}