#include <iostream>

int main()
{
	int T = 1;
	while (T) {
		int L, P, V;
		scanf("%d %d %d", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0)
			return 0;
		int ans = 0;
		ans += V / P * L;
		ans += (V%P > L) ? L : V % P;

		printf("Case %d: %d\n", T, ans);
		T++;
	}
}