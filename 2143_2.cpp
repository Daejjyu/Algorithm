#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, M, A[1000], B[1000];
int main()
{
	scanf("%d %d", &T, &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", A + i);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", B + i);
	}

	vector<int> sumA, sumB;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		sum += A[i];
		sumA.push_back(sum);
		for (int j = i + 1; j < N; j++)
		{
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int sum = 0;
		sum += B[i];
		sumB.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += B[j];
			sumB.push_back(sum);
		}
	}
	sort(sumB.begin(), sumB.end());

	long long ans = 0;
	for (int i = 0; i < sumA.size(); i++)
	{
		int lo = lower_bound(sumB.begin(), sumB.end(), T - 1 * sumA[i]) - sumB.begin();
		int hi = upper_bound(sumB.begin(), sumB.end(), T - 1 * sumA[i]) - sumB.begin();
		ans += hi - lo;
	}
	printf("%lld", ans);
}