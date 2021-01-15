#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000], B[1000];

int main()
{
	int O, M, N;
	scanf("%d %d %d", &O, &M, &N);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", A + i);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", B + i);
	}
	vector<int> AS(1, 0), BS(1, 0);
	int lo = 0;
	int hi = lo;
	int sum = 0;

	while (lo < M) {
		sum += A[hi];
		if (sum <= O) {
			AS.push_back(sum);
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
		if (sum <= O) {
			BS.push_back(sum);
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

	sort(AS.begin(), AS.end());
	sort(BS.begin(), BS.end());

	int ans = 0;
	for (int i = 0; i < AS.size(); i++)
	{
		int value = AS[i];

		int loB = lower_bound(BS.begin(), BS.end(), O - value) - BS.begin();
		int hiB = upper_bound(BS.begin(), BS.end(), O - value) - BS.begin();
		ans += hiB - loB;
	}
	printf("%d", ans);
}