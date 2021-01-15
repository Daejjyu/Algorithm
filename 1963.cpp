#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

const int MAX = 10000;

int era[MAX] = { 1,1 };
int visited[MAX];
queue<int> q;

int A, B;
int ans;
bool possible = false;

void eratho()
{
	for (int i = 2; i < MAX; i++)
	{
		if (era[i] == 0) {
			for (int j = 2; i*j < MAX; j++)
			{
				era[i*j] = 1;
			}
		}
	}
}

void bfs(int idx)
{
	if (idx == B) {
		possible = true;
		return;
	}
	q.push(idx);
	ans = 1;
	visited[idx] = 1;
	while (!q.empty()) {
		int curSize = q.size();
		while (curSize--)
		{
			int num = q.front();
			q.pop();

			string str = to_string(num);
			for (int i = 0; i < str.size(); i++)
			{
				for (int j = 0; j < 10; j++)
				{
					char temp = str[i];
					str[i] = '0' + j;
					int nextN = atoi(str.c_str());
					str[i] = temp;
					if (nextN < 1000)
						continue;
					if (!visited[nextN] && era[nextN] == 0) {
						q.push(nextN);
						visited[nextN] = 1;
						if (nextN == B) {
							possible = true;
							while (!q.empty())
								q.pop();
							return;
						}
					}
				}
			}
		}
		ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	eratho();
	int T;
	cin >> T;
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		ans = 0;
		possible = false;
		cin >> A >> B;

		bfs(A);

		if (possible)
			cout << ans << "\n";
		else
			cout << "impossible" << "\n";
	}
}