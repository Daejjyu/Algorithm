#include <iostream>
#include <vector>
using namespace std;

int arr[25];

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	int num = 0;
	for (int i = 0; i < N; i++)
	{
		num *= A;
		num += arr[i];
	}
	vector<int> ans;
	while (num) {
		ans.push_back(num %B);
		num /= B;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[ans.size() - 1 - i]);
	}
}