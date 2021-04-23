#include <string>
#include <vector>
#include <iostream>

using namespace std;

int leftPos;
int rightPos;
bool rightH = false;

int dist(int x, int y)
{
	int temp = 0;
	if (x == y)
		return 0;
	int bigN = x > y ? x : y;
	int smallN = x < y ? x : y;
	while (bigN - 3 > smallN) {
		bigN -= 3;
		temp++;
	}
	if (bigN - smallN == 2) {
		bigN--;
		temp++;
	}
	if (bigN - smallN == 3 || bigN - smallN == 1)
		return temp + 1;
}

string solution(vector<int> numbers, string hand)
{
	if (hand[0] == 'r')
		rightH = true;
	else
		rightH = false;
	leftPos = 10;
	rightPos = 12;
	string answer = "";

	for (int i = 0; i < numbers.size(); i++)
	{
		int d;
		if (numbers[i] == 0)
			d = 11;
		else if ('1' <= numbers[i] <= '9')
			d = (int)numbers[i];

		if (d == 3 || d == 6 || d == 9) {
			answer += 'R';
			rightPos = d;
		} else if (d == 1 || d == 4 || d == 7) {
			answer += 'L';
			leftPos = d;
		} else if (d == 2 || d == 5 || d == 8 || d == 11) {
			int dR = dist(rightPos, d);
			int dL = dist(leftPos, d);

			if (rightH) {
				if (dR <= dL) {
					answer += 'R';
					rightPos = d;
				} else {
					answer += 'L';
					leftPos = d;
				}
			} else {
				if (dL <= dR) {
					answer += 'L';
					leftPos = d;
				} else {
					answer += 'R';
					rightPos = d;
				}
			}
		}
	}
	return answer;
}
int main(void)
{
}