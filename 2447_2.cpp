#include<iostream>

char map[2200][2200];

void star(int r, int c, int N)
{
	if (N == 3) {
		for (int i = r; i < r + 3; i++)
		{
			for (int j = c; j < c + 3; j++)
			{
				if (i == r + 1 && j == c + 1)
					map[i][j] = ' ';
				else
					map[i][j] = '*';
			}
		}
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!(i == 1 && j == 1))
				star(r + i * N / 3, c + j * N / 3, N / 3);
			else
				for (int p = r + N / 3; p < r + 2 * N / 3; p++)
				{
					for (int k = c + N / 3; k < c + 2 * N / 3; k++)
					{
						map[p][k] = ' ';
					}
				}
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	star(0, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}