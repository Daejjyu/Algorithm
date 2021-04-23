#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	if (a < 0 && b < 0)
		return a > b;
	else
		return a < b;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> arr;
	int cnt0 = 0;
	int cntM = 0;
	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		if (d == 0)
			cnt0++;
		if (d < 0)
			cntM++;
		arr.push_back(d);
	}

	sort(arr.begin(), arr.end(), cmp);
	int sum = 0;
	if (cntM % 2 == 0) {
		for (int i = N - 1; i >= 0; i--)
		{
			if (i - 1 >= 0 && arr[i] * arr[i - 1] > 0) {
				sum += arr[i] * arr[i - 1];
				if (arr[i] == 1 || arr[i - 1] == 1)
					sum += 1;
				i--;
			} else
				sum += arr[i];
		}
	} else {
		for (int i = N - 1; i >= 1; i--)
		{
			if (i - 1 >= 0 && arr[i] * arr[i - 1] > 0) {
				sum += arr[i] * arr[i - 1];
				if (arr[i] == 1 || arr[i - 1] == 1)
					sum += 1;
				i--;
			} else
				sum += arr[i];
		}
		if (cnt0 == 0)
			sum += arr[0];
	}
	printf("%d", sum);
}