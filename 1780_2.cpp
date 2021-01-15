#include<iostream>

int N;
int map[2200][2200];
int num[3];

void paper(int r, int c, int N)
{
	if (N == 1) {
		num[map[r][c] + 1]++;
		return;
	}

	int cur = map[r][c];
	bool possible = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[r + i][c + j] != cur) {
				possible = false;
				break;
			}
		}
	}
	if (possible)
		num[cur + 1]++;
	else
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				paper(r + i * N / 3, c + j * N / 3, N / 3);
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
			scanf("%d", &map[i][j]);
		}
	}
	paper(0, 0, N);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", num[i]);
	}
}