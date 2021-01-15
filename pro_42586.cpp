#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

/// <cmath> ceil �����س� �ͱ����� ��������,
// (double)����ȯ�� ��������� ����� �Ѵٴ� ���� ����
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	int day = (int)ceil(((double)100 - progresses[0]) / speeds[0]);
	int cnt = 1;
	for (int i = 1; i < progresses.size(); i++) {
		if (day >= (int)ceil(((double)100 - progresses[i]) / speeds[i]))
			cnt++;
		else {
			day = (int)ceil(((double)100 - progresses[i]) / speeds[i]);
			answer.push_back(cnt);
			cnt = 1;
		}
	}
	answer.push_back(cnt);
	for (int i = 0; i < answer.size(); i++)
		printf("%d, ", answer[i]);
	return answer;
}