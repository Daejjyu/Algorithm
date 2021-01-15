#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool btn[10];

int possible(int idx)
{
	if (idx == 0)
		if (btn[0] != 0)
			return 0;
		else
			return 1;
	int len = 0;

	while (idx) {
		int temp = idx % 10;
		if (btn[temp] == 0) {
			idx /= 10;
			len++;
		} else
			return 0;
	}
	return len;
}
int main()
{
	int M;
	int N;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		btn[num] = 1;
	}
	int ans = abs(N - 100);

	for (int i = 0; i <= 2000000; i++)
	{
		int temp = 1e8;
		if (possible(i) > 0)
			temp = abs(i - N) + possible(i);
		ans = min(ans, temp);
	}
	printf("%d", ans);
}