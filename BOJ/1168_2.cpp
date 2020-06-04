#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		arr.push_back(i + 1);
	}

	printf("<");
	int cnt = 0;
	while (!arr.empty()) {
		if (arr.size() == 1) {
			printf("%d>", arr.front());
			break;
		} else {
			cnt += K - 1;
			cnt %= arr.size();
			printf("%d, ", arr[cnt]);
			arr.erase(arr.begin() + cnt);
		}
	}
}