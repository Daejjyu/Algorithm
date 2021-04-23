#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

string goal = "123456789";
int ans;
bool possible = false;
map<string, int> visited;
queue<string> q;

int nR[4] = { 0,0,-1,1 };
int nC[4] = { 1,-1,0,0 };

void bfs(string start)
{
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			string cur = q.front();
			q.pop();
			if (cur == goal) {
				possible = true;
				return;
			}

			int z = cur.find('9');
			int r = z / 3;
			int c = z % 3;
			for (int i = 0; i < 4; i++)
			{
				int nextR = r + nR[i];
				int nextC = c + nC[i];
				if (nextR < 0 || nextC < 0 || 3 <= nextR || 3 <= nextC)
					continue;
				swap(cur[z], cur[nextR * 3 + nextC]);
				if (!visited[cur]) {
					q.push(cur);
					visited[cur] = 1;
				}
				swap(cur[z], cur[nextR * 3 + nextC]);
			}
		}
		ans++;
	}
}

int main()
{
	string num = "";
	for (int i = 0; i < 9; i++)
	{
		int d;
		scanf("%d", &d);
		char c = d + '0';
		if (c == '0')
			c = '9';
		num += c;
	}
	bfs(num);

	if (possible)
		printf("%d", ans);
	else
		printf("-1");
}