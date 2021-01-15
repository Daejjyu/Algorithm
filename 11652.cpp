#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<long long> longArr;

	int n;
	long long  d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &d);
		longArr.push_back(d);
	}
	sort(longArr.begin(), longArr.end());

	int max = 1;
	int count = 1;
	long long index = longArr[0];

	for (int i = 0; i < n - 1; i++)
	{
		if (longArr[i] == longArr[i + 1]) {
			count++;
		} else {
			count = 1;
		}
		if (count > max) {
			max = count;
			index = longArr[i];
		}
	}
	printf("%lld", index);
}