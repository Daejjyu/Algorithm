#include <iostream>
#include <algorithm>
using namespace std;

int R, C, arr[100][100];
long long ans;

long long sum(int sc, int sr, int ec, int er)
{
	long long ret = 0;
	for (int i = sr; i <= er; i++)
	{
		for (int j = sc; j <= ec; j++)
		{
			ret += arr[i][j];
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	//1
	for (int i = 0; i < C; i++)
	{
		for (int j = i + 1; j < C - 1; j++)
		{
			long long a1 = sum(0, 0, i, R - 1);
			long long a2 = sum(i + 1, 0, j, R - 1);
			long long a3 = sum(j + 1, 0, C - 1, R - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	//2
	for (int i = 0; i < R; i++)
	{
		for (int j = i + 1; j < R - 1; j++)
		{
			long long a1 = sum(0, 0, C - 1, i);
			long long a2 = sum(0, i + 1, C - 1, j);
			long long a3 = sum(0, j + 1, C - 1, R - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	//3
	for (int i = 0; i < C - 1; i++) {
		for (int j = 0; j < R - 1; j++) {
			long long a1 = sum(0, 0, i, R - 1);
			long long a2 = sum(i + 1, 0, C - 1, j);
			long long a3 = sum(i + 1, j + 1, C - 1, R - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	//4
	for (int i = C - 1; i > 0; i--) {
		for (int j = 0; j < R - 1; j++) {
			long long a1 = sum(i, 0, C - 1, R - 1);
			long long a2 = sum(0, 0, i - 1, j);
			long long a3 = sum(0, j + 1, i - 1, R - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	//5
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C - 1; j++) {
			long long a1 = sum(0, 0, C - 1, i);
			long long a2 = sum(0, i + 1, j, R - 1);
			long long a3 = sum(j + 1, i + 1, C - 1, R - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	//6
	for (int i = R - 1; i > 0; i--) {
		for (int j = 0; j < C - 1; j++) {
			long long a1 = sum(0, i, C - 1, R - 1);
			long long a2 = sum(0, 0, j, i - 1);
			long long a3 = sum(j + 1, 0, C - 1, i - 1);
			ans = max(ans, a1*a2*a3);
		}
	}
	printf("%lld", ans);
}