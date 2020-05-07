#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	char map[16][16];

	for (int i = 0; i < arr1.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i] % 2 == 1 || arr2[i] % 2 == 1)
				map[i][j] = '#';
			else
				map[i][j] = ' ';
			arr1[i] /= 2;
			arr2[i] /= 2;
		}
	}

	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	string s1;
	printf("%d", s1.size());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s1 += map[i][j];
		}
	}
	s1 += map[0][1];
	printf("%d", s1.size());

	answer.push_back(s1);

	return answer;
}