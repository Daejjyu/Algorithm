#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, M;

int card[500000];
int isHave[500000];

int low = 1e9;
int high = -1e9;
int mid;
int ans;

map<int, int> map1;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
		map1[card[i]]++;
	}
	low = 0;
	high = N - 1;

	sort(card, card + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &isHave[i]);
	}

	for (int i = 0; i < M; i++)
	{
		int tempH = high;
		int tempL = low;
		ans = 0;

		while (tempL <= tempH) {
			int mid = tempH + (tempL - tempH) / 2;
			if (card[mid] <= isHave[i]) {
				if (card[mid] == isHave[i]) {
					ans = map1[card[mid]];
					break;
				}
				tempL = mid + 1;
			} else
				tempH = mid - 1;
		}
		printf("%d ", ans);
	}
}