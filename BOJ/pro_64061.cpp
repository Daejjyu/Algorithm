#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;

	for (int i = 0; i < moves.size(); i++)
	{
		int craneIdx = moves[i] - 1;

		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][craneIdx] != 0) {
				if (!s.empty() && s.top() == board[j][craneIdx])
				{
					s.pop();
					answer += 2;
				} else
					s.push(board[j][craneIdx]);
				board[j][craneIdx] = 0;
				break;
			}
		}
	}

	printf("%d", answer);
	return answer;
}