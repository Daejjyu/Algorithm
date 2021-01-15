#include<iostream>
#include<algorithm>
using namespace std;

char goal1[8][9] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW",
				   "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
char goal2[8][9] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB",
				   "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int N, M, ans = 1e9;
char map[50][50];

void chess(int r1, int c1)
{
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[r1 + i][c1 + j] != goal1[i][j])
				ret1++;
			if (map[r1 + i][c1 + j] != goal2[i][j])
				ret2++;
		}
	}
	int ret = min(ret1, ret2);
	if (ans > ret)
		ans = ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		char c;
		scanf("%1c", &c);
		for (int j = 0; j < M; j++)
		{
			scanf("%1c", &map[i][j]);
		}
	}

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			chess(i, j);
		}
	}

	printf("%d", ans);
}