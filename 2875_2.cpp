#include<iostream>
#include<algorithm>
using namespace std;
int N, M, K;

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int maxTeam = min(N / 2, M);
	int left = N - 2 * maxTeam + M - maxTeam;

	if (K > left) {
		int minus = (K - left) / 3;
		if ((K - left) % 3) minus++;
		maxTeam -= minus;
	}

	printf("%d", maxTeam);
}