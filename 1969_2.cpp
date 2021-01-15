#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<char, int> map1;
vector<string> arr;
int N, M;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		arr.push_back(input);
	}

	string ansS = "";
	int ans = 0;
	for (int j = 0; j < M; j++)
	{
		map1.clear();
		int max = 0;
		char maxC;
		for (int i = 0; i < N; i++)
		{
			map1[arr[i][j]]++;
			if (max < map1[arr[i][j]]) {
				max = map1[arr[i][j]];
				maxC = arr[i][j];
			} else if (max == map1[arr[i][j]]) {
				maxC = min(maxC, arr[i][j]);
			}
		}
		ansS += maxC;
		ans += (N - map1[maxC]);
	}

	cout << ansS << "\n" << ans;
}