#include<iostream>

int N;
bool map[3072][3072 * 2];

void star(int r, int c, int size)
{
	if (size == 3)
		map[r][c] = map[r + 1][c + 1] = map[r + 1][c - 1] = map[r + 2][c - 2] = map[r + 2][c - 1] = map[r + 2][c] = map[r + 2][c + 1] = map[r + 2][c + 2] = 1;
	else
	{
		star(r, c, size / 2);
		star(r + size / 2, c - size / 2, size / 2);
		star(r + size / 2, c + size / 2, size / 2);
	}
}

int main()
{
	scanf("%d", &N);

	star(0, N - 1, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			if (map[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}