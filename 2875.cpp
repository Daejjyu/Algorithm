#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)

{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int maxTeam = min(N / 2, M);
	if (maxTeam < 0) maxTeam = 0;

	K -= (N - 2 * maxTeam) + (M - maxTeam);

	while (K > 0 && maxTeam > 0) {
		maxTeam--;
		K -= 3;
	}
	printf("%d", maxTeam);
}