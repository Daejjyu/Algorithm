#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> map1;

int solution(string str1, string str2)
{
	std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	if (str1.length() == 0 && str2.length() == 0)
		return 65536;

	string temp = "";
	int num1 = 0, num2 = 0;
	for (int i = 0; i < str1.length() - 1; i++)
	{
		if ('a' <= str1[i] && str1[i] <= 'z' && 'a' <= str1[i + 1] && str1[i + 1] <= 'z') {
			temp += str1.substr(i, 2);
			map1[temp]++;
			temp = "";
			num1++;
		}
	}

	int common = 0;
	for (int i = 0; i < str2.length() - 1; i++)
	{
		if ('a' <= str2[i] && str2[i] <= 'z' && 'a' <= str2[i + 1] && str2[i + 1] <= 'z') {
			temp += str2.substr(i, 2);
			if (map1[temp]) {
				common++;
				map1[temp]--;
			}
			temp = "";
			num2++;
		}
	}

	if (num1 == 0 && num2 == 0)
		return 65536;

	double answerD = (double)common / ((double)num1 + (double)num2 - (double)common);
	int answer = 65536 * answerD;
	return answer;
}