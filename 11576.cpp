#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int A, B, nA;
	scanf("%d %d %d", &A, &B, &nA);

	int sum = 0;
	while (nA--)
	{
		int d;
		scanf("%d", &d);
		sum *= A;
		sum += d;
	}
	if (sum == 0)
		printf("0");

	vector<int> arr;
	while (sum) {
		int d;
		d = sum % B;
		sum /= B;
		arr.push_back(d);
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
}