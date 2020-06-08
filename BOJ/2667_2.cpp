#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 25;
int map[MAX][MAX];
int num = 1;
int N;

int R[4] = { 0,0,-1,1 };
int C[4] = { 1,-1,0,0 };

void dfs(int r, int c)
{
	map[r][c] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + R[i];
		int nextC = c + C[i];
		if (nextR < 0 || N <= nextR || nextC < 0 || N <= nextC)
			continue;
		if (map[nextR][nextC] == 1) {
			num++;
			dfs(nextR, nextC);
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	vector<int> ans;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1) {
				dfs(i, j);
				ans.push_back(num);
				num = 1;
			}
		}
	}

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
}