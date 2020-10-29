#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> map1;

bool cmp(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b)
{
	if (map1[a.first.first] == map1[b.first.first]) {
		if (a.first.second == b.first.second)
			return a.second < b.second;
		return a.first.second > b.first.second;
	}
	return map1[a.first.first] > map1[b.first.first];
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<pair<pair<string, int>, int>> vec;//genre,play,index
	for (int i = 0; i < genres.size(); i++)
	{
		map1[genres[i]] += plays[i];
		vec.push_back({ {genres[i],plays[i]},i });
	}
	sort(vec.begin(), vec.end(), cmp);

	map<string, int> IndexMap;
	vector<int> answer;
	for (int i = 0; i < vec.size(); i++) {
		if (IndexMap[vec[i].first.first] < 2) {
			answer.push_back(vec[i].second);
			IndexMap[vec[i].first.first]++;
		}
	}
	return answer;
}