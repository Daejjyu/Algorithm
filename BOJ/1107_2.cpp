#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N, M, broken[11], len;

bool possible(int idx)
{
	len = 0;
	if (idx == 0)
		if (broken[0])
			return 0;
		else {
			len = 1;
			return 1;
		}

	while (idx) {
		int temp = idx % 10;
		if (!broken[temp]) {
			idx /= 10;
			len++;
		} else
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int d;
		scanf("%d", &d);
		broken[d] = 1;
	}

	int ans = abs(N - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		int cnt = 1e9;
		if (possible(i))
			cnt = abs(N - i) + len;
		ans = min(ans, cnt);
	}
	printf("%d", ans);
}