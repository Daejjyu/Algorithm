#include<iostream>
#include<algorithm>
using namespace std;

int twoFive(int num, int range)
{
	int ans = 0;
	for (long long i = num; range / i >= 1; i *= num)
	{
		ans += range / i;
	}
	return ans;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int two, five;
	two = twoFive(2, N);
	five = twoFive(5, N);
	if (M != 0) {
		two -= twoFive(2, M);
		five -= twoFive(5, M);
		
	}

	if (N != M) {
		two -= twoFive(2, N - M);
		five -= twoFive(5, N - M);
	}

	printf("%d", min(two, five));
}