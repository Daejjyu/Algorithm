#include <cstdio>

char arr[10000][10000];

void star(int r, int c, int n)
{
	if (n == 1) {
		arr[r][c] = '*';
	} else {
		int nn = n / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) {
					for (int k = 0; k < nn; k++)
					{
						for (int p = 0; p < nn; p++)
						{
							arr[r + i * nn + k][c + j * nn + p] = ' ';
						}
					}
				} else {
					star(r + i * nn, c + j * nn, nn);
				}
			}
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	star(0, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}