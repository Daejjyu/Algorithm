#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int goal, M, N, A[1000], B[1000];
int main()
{
	scanf("%d %d %d", &goal, &M, &N);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", A + i);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", B + i);
	}

	vector<int> sumA(1, 0), sumB(1, 0);

	int lo = 0, hi = lo, sum = 0;
	while (lo < M) {
		sum += A[hi];
		if (sum <= goal) {
			sumA.push_back(sum);
			hi++;
		} else {
			lo++;
			hi = lo;
			sum = 0;
		}

		if (hi == M)
			hi = 0;
		if ((!hi && !lo) || hi + 1 == lo) {
			lo++;
			hi = lo;
			sum = 0;
		}
	}

	lo = 0;	hi = lo; sum = 0;
	while (lo < N) {
		sum += B[hi];
		if (sum <= goal) {
			sumB.push_back(sum);
			hi++;
		} else {
			lo++;
			hi = lo;
			sum = 0;
		}

		if (hi == N)
			hi = 0;
		if ((!hi && !lo) || hi + 1 == lo) {
			lo++;
			hi = lo;
			sum = 0;
		}
	}

	sort(sumB.begin(), sumB.end());

	long long ans = 0;
	for (int i = 0; i < sumA.size(); i++)
	{
		int lo = lower_bound(sumB.begin(), sumB.end(), goal - 1 * sumA[i]) - sumB.begin();
		int hi = upper_bound(sumB.begin(), sumB.end(), goal - 1 * sumA[i]) - sumB.begin();
		ans += hi - lo;
	}
	printf("%lld", ans);
}