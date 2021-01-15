#include<iostream>
#include<map>
using namespace std;

int N, K, arr[100];
map<int, int> visited;
int cnt, ans;

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", arr + i);
	}

	for (int i = 0; i < K; i++)
	{
		int cur = arr[i];
		if (visited[cur])
			continue;
		if (!visited[cur] && cnt < N) {
			cnt++;
			visited[cur] = 1;

			continue;
		} else {
			ans++;
			int maxVal = 0, out;
			for (int k = 1; k <= K; k++)//물건개수
			{
				if (!visited[k])//플러그에서 뺄 것만 탐색
					continue;
				int idx = 0;
				for (int j = i + 1; j < K; j++)
				{
					//이후로 안나오거나 가장 나중에 나오는거 계산
					idx++;
					if (arr[j] == k)
						break;
				}
				if (maxVal < idx) {
					maxVal = idx;
					out = k;
				}
			}
			visited[out]--;
			visited[cur]++;
		}
	}
	printf("%d", ans);
}

/*
testcase 모음

2 7
2 3 2 3 1 2 7
답: 2

2 5
5 2 2 3 5
답: 1

2 4
5 3 1 5
답: 1

3 6
1 1 1 1 2 3
답: 0

3 8
1 2 3 4 1 1 1 2
답: 1

2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
답: 2

1 3
1 2 1
답: 2
*/