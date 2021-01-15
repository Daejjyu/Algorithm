#include<iostream>
#include<algorithm>
using namespace std;

int L, P, V;
int main()
{
	int cnt = 0;
	while (1) {
		cnt++;
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V)
			break;

		int ans = 0;
		ans += V / P * L;
		ans += min(L, V%P);

		printf("Case %d: %d\n", cnt, ans);
	}
}