#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[201][201];
vector<int> ans;

int A, B, C;

void dfs(int a, int b)
{
	visited[a][b] = 1;
	int c = C - (a + b);
	if (a == 0)
		ans.push_back(c);

	//a->b
	if (a + b > B) {
		if (!visited[a - (B - b)][B])
			dfs(a + b - B, B);
	} else
		if (!visited[0][a + b])
			dfs(0, a + b);
	//a->c
	if (!visited[0][b])
		dfs(0, b);
	//b->a
	if (a + b > A) {
		if (!visited[A][b - (A - a)])
			dfs(A, b - (A - a));
	} else
		if (!visited[a + b][0])
			dfs(a + b, 0);
	//b->c
	if (!visited[a][0])
		dfs(a, 0);
	//c->a
	if (a + c > A) {
		if (!visited[A][b])
			dfs(A, b);
	} else
		if (!visited[a + c][b])
			dfs(a + c, b);
	//c->b
	if (b + c > B) {
		if (!visited[a][B])
			dfs(a, B);
	} else
		if (!visited[a][b + c])
			dfs(a, b + c);
}

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	dfs(0, 0);

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}