#include<vector>
#include <iostream>
using namespace std;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector <int > arr;
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	int index = 0;
	printf("<");
	while (arr.size()) {
		index += m - 1;
		index %= arr.size();
		if (arr.size() != 1)
			printf("%d, ", arr[index]);
		else
			printf("%d", arr[index]);
		arr.erase(arr.begin() + index);
	}
	printf(">");
}