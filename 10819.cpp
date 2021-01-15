#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
int ans;

void calculate()
{
	int sum = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		sum += abs(arr[i] - arr[i - 1]);
	}
	ans = max(ans, sum);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		arr.push_back(d);
	}
	sort(arr.begin(), arr.end());
	do {
		calculate();
	} while (next_permutation(arr.begin(), arr.end()));

	printf("%d", ans);
}