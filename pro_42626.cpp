#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//�� �켱���� ť priority_queue<int,vector<int>,greater<int>> q; ��������.

int solution(vector<int> scoville, int K)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
	}
	int size = scoville.size();
	while (!q.empty()) {
		if (q.top() > K)
			return scoville.size() - q.size();
		else {
			if (q.size() == 1)
				return -1;
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			q.push(a + b * 2);
		}
	}
	return -1;
}