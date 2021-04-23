#include<iostream>
using namespace std;

int main()
{
	long long A, B, C, D;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	int temp = B;
	while (temp) {
		temp /= 10;
		A *= 10;
	}
	temp = D;
	while (temp) {
		temp /= 10;
		C *= 10;
	}
	long long ans = A + B + C + D;
	printf("%lld", ans);
}