#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems)
{
	vector<int> answer;
	map<string, int> map1;
	for (int i = 0; i < gems.size(); i++)
	{
		map1[gems[i]] = 1;
	}
	int num = map1.size();
	printf("%d", num);
	for (int i = 0; i < gems.size(); i++)
	{
		map1[gems[i]] = 0;
	}
	if (num == 1) {
		answer.push_back(1);
		answer.push_back(1);
		return answer;
	}

	int lo = 0, hi = 0;
	int minlen = 1e9;
	bool allN;
	while (1) {
		allN = true;
		for (int i = 0; i < gems.size(); i++)
		{
			if (map1[gems[i]] == 0)
			{
				allN = false;
				break;
			}
		}

		if (allN) {
			map1[gems[lo++]]--;
		} else if (hi == gems.size()) break;
		else {
			if (hi < gems.size())
				map1[gems[hi++]]++;
		}
		if (allN) {
			int len = hi - (lo);
			if (len < minlen) {
				minlen = len;
				answer.clear();
				answer.push_back(lo - 1);
				answer.push_back(hi - 1);
			}
		}
	}

	printf("%d %d", answer[0], answer[1]);
	return answer;
}