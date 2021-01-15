#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

bool cmp(int x, int y)
{
	string sX = to_string(x);
	string sY = to_string(y);
	return sX + sY > sY + sX;
}

string solution(vector<int> numbers)
{
	sort(numbers.begin(), numbers.end(), cmp);
	string answer = "";
	//0ó�����ϸ� 0000����
	if (numbers[0] == 0)
		return "0";
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}