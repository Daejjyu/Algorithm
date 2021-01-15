#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long N;
	int B;

	vector<char> arr;

	scanf("%lld %d", &N, &B);
	while (N) {
		int r = N % B;
		char num;
		if (r > 9) {
			r = 'A' + r - 10;
			num = r;
		} else {
			num = '0' + r;
		}
		arr.push_back(num);
		N /= B;
	}
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}
}