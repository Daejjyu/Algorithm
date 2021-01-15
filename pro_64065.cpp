#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s)
{
	vector<int> answer;

	vector<vector<int>> numbers;
	vector<int> temp;

	string num = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{') {
		} else if (s[i] == '}') {
			temp.push_back(atoi(num.c_str()));
			numbers.push_back(temp);
			temp.clear();
			num = "";
			i++;
		} else if (s[i] == ',') {
			temp.push_back(atoi(num.c_str()));
			num = "";
		} else {
			num += s[i];
		}
	}

	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++)
	{
		sort(numbers[i].begin(), numbers[i].end());
	}

	answer.push_back(numbers[0][0]);
	for (int i = 0; i < numbers.size(); i++)
	{
		int j = 0;
		for (j = 0; j < numbers[i].size - 1; j++)
		{
			if (numbers[i - 1][j] != numbers[i][j]) {
				answer.push_back(numbers[i][j]);
				break;
			}
		}
	}

	return answer;
}