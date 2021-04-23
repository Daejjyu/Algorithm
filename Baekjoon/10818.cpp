#include <cstdio>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, a;
	scanf("%d", &n);
	int min = 1000000;
	int max = -1000000;
	while (n--)
	{
		scanf("%d", &a);
		if (a > max)
			max = a;
		if (a < min)
			min = a;
	}
	printf("%d %d", min, max);
}