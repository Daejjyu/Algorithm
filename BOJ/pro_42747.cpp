#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
	sort(citations.begin(), citations.end(), greater<int>());
	int answer = citations[0] + 1;
	while (--answer) {
		if (answer > citations.size())
			continue;
		if (citations[answer - 1] >= answer)
			return answer;
	}
	return 0;
}