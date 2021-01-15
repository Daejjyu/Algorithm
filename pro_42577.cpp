#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	map<string, int> map1;
	for (int i = 0; i < clothes.size(); i++) {
		map1[clothes[i][1]]++;
	}
	vector<pair<string, int>> vec(map1.begin(), map1.end());
	int answer = 1;
	for (int i = 0; i < vec.size(); i++) {
		answer *= (vec[i].second + 1);
	}

	return answer - 1;
}