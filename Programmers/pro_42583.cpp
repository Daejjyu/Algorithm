#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int time = 0, weightSum = 0, index = 0;
	queue<int> que;

	while (1) {
		time++;

		if (que.size() == bridge_length) {
			weightSum -= que.front();
			que.pop();
		}

		if (weightSum + truck_weights[index] <= weight) {
			if (index == truck_weights.size() - 1) {
				time += bridge_length;
				break;
			}
			weightSum += truck_weights[index];
			que.push(truck_weights[index]);
			index++;
		} else {
			que.push(0);
		}
	}

	return time;
}