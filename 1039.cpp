#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

int N, K;
bool possible = false;
int ans = 0;
map<int, int> map1;

queue<int> q;

void bfs(int idx)
{
	int cnt = 1;
	q.push(idx);
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--) {
			int num = q.front();
			q.pop();

			string s = to_string(num);
			for (int i = 0; i < s.size(); i++)
			{
				for (int j = i + 1; j < s.size(); j++)
				{
					if (i == 0 && s[j] == '0')
						continue;
					swap(s[i], s[j]);
					if (!map1[stoi(s)]) {
						q.push(stoi(s));
						map1[stoi(s)]++;
					}
					if (cnt == K) {
						possible = true;
						if (ans < stoi(s))
							ans = stoi(s);
					}
					swap(s[i], s[j]);
				}
			}
		}
		cnt++;
		map1.clear();
		if (cnt > K)
			return;
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	bfs(N);

	if (possible)
		printf("%d", ans);
	else
		printf("-1");
}