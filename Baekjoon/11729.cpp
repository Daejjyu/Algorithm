#include <cstdio>

void Hanoi(int num, int from, int left, int to)
{
	if (num == 1) {
		printf("%d %d\n", from, to);
	} else {
		Hanoi(num - 1, from, to, left);
		Hanoi(1, from, left, to);
		Hanoi(num - 1, left, from, to);
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	printf("%d\n", (1 << N) - 1);
	Hanoi(N, 1, 2, 3);
}