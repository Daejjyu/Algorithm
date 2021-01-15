#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

int main()
{
	for (int i = 1; i*(i + 1) / 2 <= 1000; i++)
	{
		vec.push_back(i*(i + 1) / 2);
	}

	int T;
	scanf("%d", &T);

	while (T--)
	{
		int K;
		scanf("%d", &K);
		int flag = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec.size(); j++)
			{
				for (int k = 0; k < vec.size(); k++)
				{
					if (vec[i] + vec[j] + vec[k] == K)
						flag = 1;
				}
			}
		}
		printf("%d\n", flag);
	}
}