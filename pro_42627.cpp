#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
//�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�. �߿�!

int solution(vector<vector<int>> jobs)
{
	vector<pair<int, int>> vec;

	for (int i = 0; i < jobs.size(); i++) {
		vec.push_back({ jobs[i][1],jobs[i][0] });
	}
	sort(vec.begin(), vec.end());

	int time = 0;
	int start = 0;
	while (!vec.empty()) {
		if (vec[0].second <= start) {
			start += vec[0].first;
			time += start - vec[0].second;
			vec.erase(vec.begin());
		} else
			start++;
	}
	return time / jobs.size();
}