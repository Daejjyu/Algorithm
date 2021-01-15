#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 50;
int map[MAX][MAX];
int R, C;
int cnt;

int next1[8] = { 0,0,-1,1,1,1,-1,-1 };
int next2[8] = { 1,-1,0,0,1,-1,1,-1 };

void dfs(int r, int c)
{
	map[r][c] = 0;
	for (int i = 0; i < 8; i++)
	{
		int nextR = r + next1[i];
		int nextC = c + next2[i];
		if (nextR < 0 || R <= nextR || nextC < 0 || C <= nextC)
			continue;
		if (map[nextR][nextC] == 1)
			dfs(nextR, nextC);
	}
}

int main()
{
	while (1) {
		cnt = 0;
		scanf("%d %d", &C, &R);
		if (R == 0 && C == 0)
			break;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", cnt);
	}
}