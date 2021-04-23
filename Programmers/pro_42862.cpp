#include <string>
#include <vector>

using namespace std;
//���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. �̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
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