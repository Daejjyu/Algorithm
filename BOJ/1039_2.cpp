#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;

string N;
int K;
bool possible = false;
int ans;
queue<string> q;
map<string, int> visited;

void bfs(string start)
{
	int cnt = 1;
	q.push(start);
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--)
		{
			string cur = q.front();
			q.pop();

			for (int i = 0; i < cur.size(); i++)
			{
				for (int j = i + 1; j < cur.size(); j++)
				{
					if (i == 0 && cur[j] == '0')
						continue;
					swap(cur[i], cur[j]);
					if (!visited[cur]) {
						q.push(cur);
						visited[cur] = 1;
					}
					if (cnt == K && stoi(cur) > ans) {
						possible = true;
						ans = stoi(cur);
					}
					swap(cur[i], cur[j]);
				}
			}
		}
		cnt++;
		visited.clear();
		if (cnt > K)
			return;
	}
}

int main()
{
	cin >> N >> K;
	bfs(N);

	if (possible)
		printf("%d", ans);
	else
		printf("-1");
}