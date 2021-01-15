#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int value[100], weight[100];
int N, K;
int dp[101][100001];

int bag(int idx, int capa)
{
	int &ret = dp[idx][capa];
	if (ret != -1)
		return ret;
	if (idx == N)
		return ret = 0;
	ret = 0;
	ret = bag(idx + 1, capa);

	if (capa >= weight[idx])
		ret = max(ret, bag(idx + 1, capa - weight[idx]) + value[idx]);

	return ret;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", weight + i, value + i);
	}
	memset(dp, -1, sizeof(dp));

	printf("%d", bag(0, K));
}