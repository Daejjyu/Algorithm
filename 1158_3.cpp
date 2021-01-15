#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		q.push(i + 1);
	}

	printf("<");
	while (!q.empty())
	{
		if (q.size() == 1) {
			printf("%d>", q.front());
			break;
		} else {
			for (int i = 1; i < K; i++)
			{
				q.push(q.front());
				q.pop();
			}
			printf("%d, ", q.front());
			q.pop();
		}
	}
}