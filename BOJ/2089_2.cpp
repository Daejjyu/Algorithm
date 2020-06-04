#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	if (N == 0)
		printf("0");
	vector<int> ans;

	while (N != 0) {
		int next;
		if (N < 0)
		{
			N *= -1;
			next = N / 2;
			int left = N % 2;
			ans.push_back(left);
			if (N % 2 != 0)
				next++;
		} else {
			next = N / 2;
			int left = N % 2;
			ans.push_back(left);
			next *= -1;
		}
		N = next;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[ans.size() - 1 - i]);
	}
}