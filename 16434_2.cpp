#include<iostream>
#include<algorithm>
using namespace std;

int room1[123456], room2[123456], room3[123456];
int N, initAtk;

bool possible(long long hp)
{
	long long curHp = hp;
	long long atk = initAtk;
	for (int i = 0; i < N; i++)
	{
		if (room1[i] == 1) {
			long long mobAtk = room2[i];
			long long mobHp = room3[i];

			long long mobLife = mobHp / atk;
			if (mobHp%atk) mobLife++;
			long long life = curHp / mobAtk;
			if (curHp%mobAtk) life++;

			if (mobLife > life)
				return false;

			curHp -= (mobLife - 1) * mobAtk;
		} else {
			atk += room2[i];
			curHp = min(hp, curHp + room3[i]);
		}
	}
	return true;
}
int main()
{
	scanf("%d %d", &N, &initAtk);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", room1 + i, room2 + i, room3 + i);
	}

	long long lo = 0, hi = 9e18;
	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		if (possible(mid))
			hi = mid;
		else
			lo = mid;
	}
	printf("%lld", hi);
}