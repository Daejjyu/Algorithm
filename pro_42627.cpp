#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
//하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다. 중요!

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