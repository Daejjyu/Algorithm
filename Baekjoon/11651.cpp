#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> xyArr(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &xyArr[i].first, &xyArr[i].second);
	}

	sort(xyArr.begin(), xyArr.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d", xyArr[i].first, xyArr[i].second);
	}
}