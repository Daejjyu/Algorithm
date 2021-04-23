#include <cstdio>

int arr[64][64];

int cnt;

void zip(int r, int c, int n)
{
	if (n == 1) {
		printf("%d", arr[r][c]);
		return;
	}

	bool flag = true;
	int pivot = arr[r][c];

	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (pivot != arr[i][j])
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}

	if (flag) printf("%d", pivot);
	else {
		printf("(");
		int nn = n / 2;
		zip(r, c, nn);
		zip(r, c + nn, nn);
		zip(r + nn, c, nn);
		zip(r + nn, c + nn, nn);
		printf(")");
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	zip(0, 0, N);
}