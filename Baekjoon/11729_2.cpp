#include<iostream>

int N;

void Hanoi(int size, int from, int left, int to)
{
	if (size == 1)
		printf("%d %d\n", from, to);
	else {
		Hanoi(size - 1, from, to, left);
		Hanoi(1, from, left, to);
		Hanoi(size - 1, left, from, to);
	}
}

int main()
{
	scanf("%d", &N);

	printf("%d\n", (1 << N) - 1);
	Hanoi(N, 1, 2, 3);
}