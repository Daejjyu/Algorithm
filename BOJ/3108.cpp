#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int fx[1001], fy[1001], tx[1001], ty[1001];
bool visit[1001];

bool coordChecking(int a, int b)
{
	return (tx[a] < fx[b] || ty[a] < fy[b] || fx[b] < fx[a] && tx[a] < tx[b] && fy[b] < fy[a] && ty[a] < ty[b]);
}

void dfs(int idx)
{
	visit[idx] = 1;
	for (int i = 0; i <= N; i++) {
		if (visit[i]) continue;
		if (!coordChecking(idx, i) && !coordChecking(i, idx))
			dfs(i);
	}
}

int main()
{
	scanf("%d", &N);
	bool s = false;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", fx + i, fy + i, tx + i, ty + i);
		if (fx[i] > tx[i]) swap(fx[i], tx[i]);
		if (fy[i] > ty[i]) swap(fy[i], ty[i]);
	}

	int sol = 0;
	for (int i = 0; i <= N; i++) {
		if (visit[i]) continue;

		dfs(i);
		sol += 1;
	}
	cout << sol - 1;
}