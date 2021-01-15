#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
//���� ���� ���������� Ʋ�Ⱦ���
vector<pair<int, int>> vec;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back({ min(a,b),max(a,b) });
	}
	sort(vec.begin(), vec.end());

	int last = -(1e9 + 1);
	long long ans = 0;
	int first = -(1e9 + 1);
	for (int i = 0; i < N; i++) {
		if (last < vec[i].first) {
			ans += last - first;
			first = vec[i].first;
		}
		last = max(last, vec[i].second);
	}
	ans += last - first;
	printf("%lld", ans);
}