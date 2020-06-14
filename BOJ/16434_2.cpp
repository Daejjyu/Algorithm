#include<iostream>

int room1[123456];
int room2[123456];
int room3[123456];

int N, initAtk;

bool possible(long long mid)
{
	long long hp = mid;
	long long curAtk = initAtk;
	for (int i = 0; i < N; i++)
	{
		if (room1[i] == 1) {
			long long mobAtk = room2[i];
			long long mobHp = room3[i];

			long long mobLife = mobHp / curAtk;
			if (mobHp%curAtk != 0)
				mobLife++;
			long long life = hp / mobAtk;
			if (hp%mobAtk != 0)
				life++;

			if (mobLife > life)
				return false;
			else
				hp -= (mobLife - 1)*mobAtk;
		} else {
			curAtk += room2[i];
			if (hp + room3[i] < mid)
				hp += room3[i];
			else
				hp = mid;
		}
	}
	return true;
}

int main(void)
{
	scanf("%d %d", &N, &initAtk);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", room1 + i, room2 + i, room3 + i);
	}

	long long lo = 0, hi = 9223372036854775780;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (possible(mid)) hi = mid;
		else lo = mid;
	}
	printf("%lld", hi);
}