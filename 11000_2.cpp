#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
pair<int, int> arr[200000];
int N;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + N);
	q.push(arr[0].second);
	for (int i = 1; i < N; i++)
	{
		if (q.top() <= arr[i].first) {
			q.pop();
			q.push(arr[i].second);
		} else
			q.push(arr[i].second);
	}
	printf("%d", q.size());
}