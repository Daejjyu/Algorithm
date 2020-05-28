#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[4000], B[4000], C[4000], D[4000];

vector<int> AB, CD;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", A + i, B + i, C + i, D + i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	long long  ans = 0;
	for (int i = 0; i < AB.size(); i++)
	{
		int value = AB[i];
		int lo = lower_bound(CD.begin(), CD.end(), -value) - CD.begin();
		int hi = upper_bound(CD.begin(), CD.end(), -value) - CD.begin();

		if (CD[lo] == -value)
			ans += hi - lo;
	}
	printf("%lld", ans);
}