#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int N;
pair<int, int> arr[200000];
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + N);

	q.push(arr[0].second);

	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (q.top() <= arr[i].first) {
			q.pop();
			q.push(arr[i].second);
		} else {
			q.push(arr[i].second);
		}
	}
	printf("%d", q.size());
}

//우선순위 큐를 이용해 들어갈 수 있으면 들어가고, 못들어가면 넣어줌
// 어차피 작은게 top이므로 항상 진행중인 강의실 중 가장 빨리 끝나는 곳에 들어간다.
// 시작시간으로 정렬되어있으므로 모순 x