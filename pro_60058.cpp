#include <string>
#include <vector>

using namespace std;

string solution(string p)
{
	string answer = "";

	if (p.length() == 0) return answer;

	bool possible = true;
	int left = 0, right = 0;

	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(') left++;
		if (p[i] == ')') right++;
		if (left < right) possible = false;

		if (left == right) {
			if (!possible) {
				answer += '(';
				answer += solution(p.substr(i + 1));
				answer += ')';
				for (int j = 1; j < i; j++)
				{
					if (p[j] == '(') answer += ')';
					if (p[j] == ')') answer += '(';
				}
				return answer;
			} else {
				answer += p.substr(0, i + 1);
				answer += solution(p.substr(i + 1));
				return answer;
			}
		}
	}
	return answer;
}