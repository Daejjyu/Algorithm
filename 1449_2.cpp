#include<iostream>
#include<algorithm>
using namespace std;

int N, L, map[1001];
int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		map[d] = 1;
	}

	int ans = 0;
	for (int i = 1; i < 1001; i++)
	{
		if (map[i] == 1) {
			i += L - 1;
			ans++;
		}
	}

	printf("%d", ans);
}