#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int ans1[5] = { 1, 2, 3, 4, 5 };
int ans2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int ans3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < answers.size(); i += 5) {
		for (int j = 0; j < 5 && j < answers.size(); j++) {
			if (answers[i + j] == ans1[j])
				sum1++;
		}
	}
	for (int i = 0; i < answers.size(); i += 8) {
		for (int j = 0; j < 8 && j < answers.size(); j++) {
			if (answers[i + j] == ans2[j])
				sum2++;
		}
	}
	for (int i = 0; i < answers.size(); i += 10) {
		for (int j = 0; j < 10 && j < answers.size(); j++) {
			if (answers[i + j] == ans3[j])
				sum3++;
		}
	}
	int maxN = max(sum1, sum2);
	maxN = max(maxN, sum3);
	vector<int> answer;
	if (sum1 == maxN)
		answer.push_back(1);
	if (sum2 == maxN)
		answer.push_back(2);
	if (sum3 == maxN)
		answer.push_back(3);
	return answer;
}