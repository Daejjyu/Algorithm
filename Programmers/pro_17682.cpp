#include <string>

using namespace std;

int solution(string dartResult)
{
	int answer = 0;

	int num[3];
	int cnt = 0;
	int temp = 0;
	for (int i = 0; i < dartResult.size(); i++)
	{
		if (dartResult[i] == '*') {
			num[cnt] *= 2; if (cnt > 1) num[cnt - 1] *= 2;
		} else if (dartResult[i] == '#') {
			num[cnt] *= -1;
		} else if (dartResult[i] == 'S') {
			continue;
		} else if (dartResult[i] == 'D') {
			num[cnt] *= num[cnt];
		} else if (dartResult[i] == 'T') {
			num[cnt] = num[cnt] * num[cnt] * num[cnt];
		} else {
			if (dartResult[i + 1] == '0') {
				num[cnt++] = 10;
				i++;
			} else
				num[cnt] = dartResult[i] - '0';
		}
	}
	answer += num[0] + num[1] + num[2];
	return answer;
}