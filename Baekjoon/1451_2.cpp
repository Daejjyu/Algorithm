#include<iostream>
#include<algorithm>
using namespace std;

int R, C, map[100][100];

long long box(int r1, int c1, int r2, int c2)
{
	long long sum = 0;
	for (int i = r1; i < r2; i++)
	{
		for (int j = c1; j < c2; j++)
		{
			sum += map[i][j];
		}
	}
	return sum;
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	long long ans = 0;
	// ㅣㅣ
	for (int i = 1; i < C; i++)
	{
		for (int j = i + 1; j < C; j++)
		{
			ans = max(ans, box(0, 0, R, i)*box(0, i, R, j)*box(0, j, R, C));
		}
	}

	// =
	for (int i = 1; i < R; i++)
	{
		for (int j = i + 1; j < R; j++)
		{
			ans = max(ans, box(0, 0, i, C)*box(i, 0, j, C)*box(j, 0, R, C));
		}
	}

	//ㅜ
	for (int k = 1; k < R; k++)
	{
		for (int i = 1; i < C; i++)
		{
			ans = max(ans, box(0, 0, k, C)*box(k, 0, R, i)*box(k, i, R, C));
		}
	}

	//ㅗ
	for (int k = 1; k < R; k++)
	{
		for (int i = 1; i < C; i++)
		{
			ans = max(ans, box(0, 0, k, i)*box(0, i, k, C)*box(k, 0, R, C));
		}
	}

	//ㅏ
	for (int k = 1; k < C; k++)
	{
		for (int i = 1; i < R; i++)
		{
			ans = max(ans, box(0, 0, R, k)*box(0, k, i, C)*box(i, k, R, C));
		}
	}

	//ㅓ
	for (int k = 1; k < C; k++)
	{
		for (int i = 1; i < R; i++)
		{
			ans = max(ans, box(0, 0, i, k)*box(i, 0, R, k)*box(0, k, R, C));
		}
	}
	printf("%lld", ans);
}