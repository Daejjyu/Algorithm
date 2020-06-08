#include<iostream>
#include<map>
using namespace std;

map<int, int> visited;

int ans1, ans2;
int A, P;

int pow(int a, int b)
{
	int temp = a;
	b--;
	while (b--) {
		a *= temp;
	}
	return a;
}

void dfs(int idx)
{
	visited[idx]++;
	if (visited[idx] == 1)
		ans1++;
	if (visited[idx] == 2)
		ans2++;
	if (visited[idx] == 3)
		return;
	int next = 0;
	int temp = idx;
	while (temp) {
		next += pow(temp % 10, P);
		temp /= 10;
	}
	dfs(next);
}

int main()
{
	scanf("%d %d", &A, &P);

	dfs(A);
	printf("%d", ans1 - ans2);
}