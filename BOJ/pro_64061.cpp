#include <string>
#include <vector>
#include <stack>
int index[31];
using namespace std;
// ����� ������ ������ return �ϵ��� solution �Լ��� �ϼ�
int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	stack<int> result;

	for (int i = 0; i < moves.size(); i++) {
		int moveNum = moves[i] - 1;

		while (index[moveNum] < board.size() && board[index[moveNum]][moveNum] == 0) {
			index[moveNum]++;
		}

		if (index[moveNum] < board.size() && board[index[moveNum]][moveNum] != 0) {
			if (!result.empty() && result.top() == board[index[moveNum]][moveNum]) {
				result.pop();
				answer += 2;
			} else result.push(board[index[moveNum]][moveNum]);
			index[moveNum]++;
		}
	}

	return answer;
}