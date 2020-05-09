#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>
using namespace std;

long long visited[27][27];
int C[4] = { 1,0,-1,0 };//동남서북	//direction 0123
int R[4] = { 0,1,0,-1 };

int mapSize;

long long answer = 1e20;
vector<vector<int>> board1;
void dfs(int r, int c, int direction, long long money)
{
	visited[r][c] = money;
	for (int i = 0; i < 4; i++)
	{
		int nR = r + R[i];
		int nC = c + C[i];
		if (nR < 0 || mapSize <= nR || nC < 0 || mapSize <= nC)
			continue;
		if (board1[nR][nC] != 1) {
			long long nextMoney = money + 1;
			if (direction != i)
				nextMoney += 5;

			if (!visited[nR][nC] || visited[nR][nC] >= nextMoney) {
				//printf("nR %d nC %d nextMoney%d\n", nR, nC, nextMoney);
				if (nR == mapSize - 1 && nC == mapSize - 1) {
					if (nextMoney < answer) {
						answer = nextMoney;
						visited[nR][nC] = nextMoney;
					}

					return;
				}
				dfs(nR, nC, i, nextMoney);
			}
		}
	}
}

long long solution(vector<vector<int>> board)
{
	board1 = board;

	mapSize = board.size();

	if (board[0][1] != 1)
		dfs(0, 1, 0, 1);
	if (board[1][0] != 1)
		dfs(1, 0, 1, 1);

	answer *= 100;
	return answer;
}