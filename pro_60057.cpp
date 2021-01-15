#include <string>

using namespace std;

int solution(string s)
{
	int answer = s.length();

	if (s.length() == 1)
		return 1;

	for (int i = 1; i <= s.length() / 2; i++)
	{
		int count = 1;
		string f = s.substr(0, i);
		string cmp, cp;

		for (int j = i; j < s.length; j += i)
		{
			cmp = s.substr(j, i);

			if (!f.compare(cmp)) {
				count++;
			} else {
				if (count == 1) {
					cp += f;
					f = cmp;
				} else {
					cp = cp + to_string(count) + f;
					f = cmp;
				}
				count = 1;
			}

			if (i + j >= s.length())
				if (count == 1) {
					cp += s.substr(j);
					break;
				} else {
					cp = cp + to_string(count) + f;
					break;
				}
		}
		answer = (answer > cp.length()) ? cp.length() : answer;
	}

	return answer;
}