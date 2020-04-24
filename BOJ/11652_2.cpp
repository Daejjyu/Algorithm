#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long l;

bool cmp(pair<l, int> a, pair<l, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	map<l, int> count;
	l bigNum;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &bigNum);
		count[bigNum]++;
	}

	vector<pair<l, int>> arr;
	int i = 0;

	for (map<l, int>::iterator it = count.begin(); it != count.end(); ++it) {
		l a = it->first;
		int b = it->second;
		arr.push_back(pair<l, int>(a, b));
	}

	sort(arr.begin(), arr.end(), cmp);

	printf("%lld", arr[0].first);
}