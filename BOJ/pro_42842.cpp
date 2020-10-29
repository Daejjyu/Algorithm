#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;
	for (int x = 1; x < 2501; x++) {
		for (int y = 1; y <= x; y++) {
			if (2 * x + 2 * y - 4 == brown && (x - 2)*(y - 2) == yellow)
			{
				answer.push_back(x);
				answer.push_back(y);
				break;
			}
		}
	}
	return answer;
}