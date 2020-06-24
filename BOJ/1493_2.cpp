#include<iostream>
#include<algorithm>
using namespace std;

int arr[20];

int main()
{
	int L, W, H, N;
	scanf("%d %d %d %d", &L, &W, &H, &N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y), arr[x] = y;
	}

	long long cnt = 0, ans = 0;
	for (int i = 19; i >= 0; i--)
	{
		cnt <<= 3;
		long long tmp = min(1LL * arr[i], 1LL * (L >> i)*(W >> i)*(H >> i) - cnt);
		cnt += tmp, ans += tmp;
	}

	printf("%lld", cnt == 1LL * L*W*H ? ans : -1);
}