#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a1, pair<int, int> a2)
{
	if (a1.second == a2.second)
		return a1.first < a2.first;
	else
		return a1.second < a2.second;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> time;

	for (int i = 0; i < N; i++)
	{
		int d1, d2;
		scanf("%d %d", &d1, &d2);
		time.push_back({ d1,d2 });
	}
	sort(time.begin(), time.end(), cmp);

	int ans = 0;
	int limit = 0;
	for (int i = 0; i < N; i++)
	{
		if (time[i].first >= limit) {
			ans++;
			limit = time[i].second;
		}
	}
	printf("%d", ans);
}