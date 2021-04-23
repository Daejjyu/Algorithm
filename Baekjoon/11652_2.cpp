#include <iostream>
#include <map>
using namespace std;

map<long long, int> map1;

int main()
{
	int N, hi = 0;
	long long ans;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		long long d;
		scanf("%lld", &d);
		if (i == 0)
			ans = d;
		map1[d]++;
		if (map1[d] > hi)
		{
			hi = map1[d];
			ans = d;
		}
		if (map1[d] == hi && d < ans)
			ans = d;
	}

	printf("%lld", ans);
}