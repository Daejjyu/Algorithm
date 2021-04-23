#include<iostream>

int N;

int map[64][64];

void quad(int r, int c, int size)
{
	int cur = map[r][c];

	bool possible = true;
	for (int i = r; i < r + size; i++)
	{
		for (int j = c; j < c + size; j++)
		{
			if (map[i][j] != cur) {
				possible = false;
				break;
			}
		}
	}
	if (possible)
		printf("%d", cur);
	else
	{
		printf("(");
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				quad(r + i * size / 2, c + j * size / 2, size / 2);
			}
		}
		printf(")");
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
	quad(0, 0, N);
}