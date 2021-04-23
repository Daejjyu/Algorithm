#include <iostream>

int arr[100];
int strike[100];
int ball[100];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", arr + i, strike + i, ball + i);
	}

	int ans = 0;
	for (int i = 123; i < 999; i++)
	{
		int idx = i;
		int third = idx % 10;
		idx /= 10;
		int second = idx % 10;
		idx /= 10;
		int first = idx % 10;
		idx /= 10;

		if (first == 0 || second == 0 || third == 0)
			continue;
		if (first == second || first == third || second == third)
			continue;

		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			int cIdx = arr[j];
			int cThird = cIdx % 10;
			cIdx /= 10;
			int cSecond = cIdx % 10;
			cIdx /= 10;
			int cFirst = cIdx % 10;
			cIdx /= 10;
			int strikeNum = 0;
			int ballNum = 0;
			if (first == cFirst)
				strikeNum++;
			if (second == cSecond)
				strikeNum++;
			if (third == cThird)
				strikeNum++;
			if (first == cSecond)
				ballNum++;
			if (first == cThird)
				ballNum++;
			if (second == cFirst)
				ballNum++;
			if (second == cThird)
				ballNum++;
			if (third == cFirst)
				ballNum++;
			if (third == cSecond)
				ballNum++;

			if (strikeNum != strike[j] || ballNum != ball[j])
				flag = false;
		}
		if (flag)
			ans++;
	}
	printf("%d", ans);
}