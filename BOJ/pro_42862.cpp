#include <string>
#include <vector>

using namespace std;
//여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
int arr[32];
int mine[32];
int solution(int n, vector<int> lost, vector<int> reserve)
{
	for (int i = 0; i < reserve.size(); i++) {
		arr[reserve[i]] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < lost.size(); i++) {
		if (arr[lost[i]]) {
			arr[lost[i]]--;
			cnt++;
			mine[lost[i]]++;
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		if (mine[lost[i]])
			continue;
		if (arr[lost[i] - 1] == 1) {
			cnt++;
			arr[lost[i] - 1] = 0;
		} else if (arr[lost[i] + 1] == 1) {
			cnt++;
			arr[lost[i] + 1] = 0;
		}
	}
	int answer = n - lost.size() + cnt;
	printf("%d %d\n", lost.size(), cnt);
	return answer;
}