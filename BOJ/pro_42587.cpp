#include <string>
#include <vector>

using namespace std;

//그냥 단순히 돌림.. 실력부족
int solution(vector<int> priorities, int location)
{
	vector<int> arr(priorities.size());
	int cnt = 1;
	int num = 0;
	int cur;
	int last;
	for (int i = 0; i < priorities.size(); i++) {
		if (priorities[i] > num) {
			num = priorities[i];
			cur = i;
			last = i;
		}
	}
	while (num)
	{
		for (int i = cur; i < priorities.size(); i++) {
			if (priorities[i] == num) {
				arr[i] = cnt;
				cnt++;
				last = i;
			}
		}
		for (int i = 0; i < cur; i++) {
			if (priorities[i] == num) {
				arr[i] = cnt;
				cnt++;
				last = i;
			}
		}
		num--;
		cur = last;
	}
	int answer = arr[location];
	return answer;
}