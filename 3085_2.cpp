#include<iostream>
using namespace std;

char map[50][50];
int N, ans;

void candy()
{
	int cnt;
	for (int i = 0; i < N; i++)
	{
		cnt = 1;//초기화 , 항상 최소 1개는 먹을 수 있음
		for (int j = 0; j < N - 1; j++)
		{
			if (map[i][j] == map[i][j + 1]) {
				cnt++;

				if (cnt > ans)
					ans = cnt;
			} else
				cnt = 1;
		}
	}

	for (int j = 0; j < N; j++)
	{
		cnt = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (map[i][j] == map[i + 1][j]) {
				cnt++;

				if (cnt > ans)
					ans = cnt;
			} else
				cnt = 1;
		}
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
			scanf("%1c", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j + 1 < N) {
				swap(map[i][j], map[i][j + 1]);
				candy();
				swap(map[i][j], map[i][j + 1]);
			}
			if (i + 1 < N) {
				swap(map[i][j], map[i + 1][j]);
				candy();
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
}