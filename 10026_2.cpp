#include<iostream>
#include<cstring>
using namespace std;

char map[100][100];
bool visited[100][100];

int N;
int rgb, rg_b;

int nR[4] = { 0,0,-1,1 };
int nC[4] = { -1,1,0,0 };

void RGB(int r, int c)
{
	visited[r][c] = 1;
	char color = map[r][c];
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + nR[i];
		int nextC = c + nC[i];
		if (nextR < 0 || nextC < 0 || N <= nextR || N <= nextC)
			continue;
		if (visited[nextR][nextC])
			continue;
		if (map[nextR][nextC] == color)
			RGB(nextR, nextC);
	}
}

void RG_B(int r, int c)
{
	visited[r][c] = 1;
	char color = map[r][c];
	if (color == 'G')
		color = 'R';
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + nR[i];
		int nextC = c + nC[i];
		if (nextR < 0 || nextC < 0 || N <= nextR || N <= nextC)
			continue;
		if (visited[nextR][nextC])
			continue;
		char nextColor = map[nextR][nextC];
		if (nextColor == 'G')
			nextColor = 'R';
		if (nextColor == color)
			RG_B(nextR, nextC);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char c;
		scanf("%c", &c);
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) {
				RGB(i, j);
				rgb++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) {
				RG_B(i, j);
				rg_b++;
			}
		}
	}

	printf("%d %d", rgb, rg_b);
}