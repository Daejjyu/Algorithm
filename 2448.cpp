#include <cstdio>

bool arr[3072][6144];

void star(int r, int c, int n)
{
	if (n == 3) {
		arr[r][c] = arr[r + 1][c - 1] = arr[r + 1][c + 1] = arr[r + 2][c - 2] = arr[r + 2][c - 1] = arr[r + 2][c] = arr[r + 2][c + 1] = arr[r + 2][c + 2] = true;
	} else {
		int nn = n / 2;
		star(r, c, nn);
		star(r + nn, c - nn, nn);
		star(r + nn, c + nn, nn);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	star(0, N - 1, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			if (arr[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}