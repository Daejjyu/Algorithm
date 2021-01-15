#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pQ;
priority_queue<int, vector<int>, less<int> > mQ;

int main()
{
	scanf("%d", &N);

	int ans = 0, num0 = 0;
	for (int i = 0; i < N; i++)
	{
		int d;
		scanf("%d", &d);
		if (d == 1)
			ans++;
		else if (d == 0)
			num0++;
		else if (d > 0)
			pQ.push(d);
		else
			mQ.push(d);
	}

	if (pQ.size() % 2)
		pQ.push(1);
	if (mQ.size() % 2)
		num0 ? mQ.push(0) : mQ.push(1);

	int lap1 = pQ.size() / 2;
	int lap2 = mQ.size() / 2;
	for (int i = 0; i < lap1; i++)
	{
		int a = pQ.top();
		pQ.pop();
		int b = pQ.top();
		pQ.pop();
		ans += a * b;
	}
	for (int i = 0; i < lap2; i++)
	{
		int a = mQ.top();
		mQ.pop();
		int b = mQ.top();
		mQ.pop();
		ans += a * b;
	}

	printf("%d", ans);
}