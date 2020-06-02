#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		string s;
		cin >> s;
		int point = 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'O')
			{
				point++;
				ans += point;
			} else
				point = 0;
		}
		printf("%d\n", ans);
	}
}