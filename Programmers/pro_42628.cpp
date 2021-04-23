#include <string>
#include <vector>
#include <queue>
using namespace std;

//큐 두개 만들고 사이즈는 따로 관리. -> 파생되는 문제 cnt로 해결

vector<int> solution(vector<string> operations)
{
	priority_queue<int> frontLargeQ;
	priority_queue<int, vector<int>, greater<int>> backLargeQ;
	int cnt = 0;
	for (int i = 0; i < operations.size(); i++) {
		/***/
		if (!cnt) {
			while (!frontLargeQ.empty()) frontLargeQ.pop();
			while (!backLargeQ.empty()) backLargeQ.pop();
		}

		char sudo = operations[i][0];
		if (sudo == 'I') {
			int num = stoi(operations[i].substr(2, operations.size()));
			frontLargeQ.push(num);
			backLargeQ.push(num);
			cnt++;
		} else if (cnt) {
			cnt--;
			if (operations[i] == "D 1") {
				frontLargeQ.pop();
			} else if (operations[i] == "D -1") {
				backLargeQ.pop();
			}
		}
	}
	vector<int> answer;
	if (cnt) {
		answer.push_back(frontLargeQ.top());
		answer.push_back(backLargeQ.top());
	} else {
		answer.push_back(0); answer.push_back(0);
	}

	return answer;
}