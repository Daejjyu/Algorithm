#include<iostream>

int main()
{
	long long N;
	scanf("%lld", &N);
	int ans = 1;
	while (N) {
		ans *= N;
		N--;
	}
	printf("%d", ans);
}