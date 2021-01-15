#include<iostream>
#include<set>
using namespace std;

int N, map[20][20];

int cut(int r1, int c1, int r2, int c2, int way)
{
	if (r1 == r2 || c1 == c2) return 0;

	set<int> cr, cc;
	int cnt = 0, stein = 0;
	for (int i = r1; i < r2; i++)
	{
		for (int j = c1; j < c2; j++)
		{
			if (map[i][j] == 1) {
				cr.insert(i);
				cc.insert(j);
				stein++;
			} else if (map[i][j] == 2)
				cnt++;
		}
	}

	if (cnt == 0) return 0;
	if (cnt == 1) return !stein;
	if (stein == 0) return 0;

	int ret = 0;

	if (way != 1) {
		for (int c : cc)
		{
			bool possible = true;
			for (int i = r1; i < r2; i++)
			{
				if (map[i][c] == 2) {
					possible = false;
					break;
				}
			}
			if (possible)
				ret += cut(r1, c1, r2, c, 1)*cut(r1, c + 1, r2, c2, 1);
		}
	}

	if (way != 2) {
		for (int r : cr)
		{
			bool possible = true;
			for (int i = c1; i < c2; i++)
			{
				if (map[r][i] == 2) {
					possible = false;
					break;
				}
			}
			if (possible)
				ret += cut(r1, c1, r, c2, 2)*cut(r + 1, c1, r2, c2, 2);
		}
	}

	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	int ans = cut(0, 0, N, N, 0);
	printf("%d", ans ? ans : -1);
}