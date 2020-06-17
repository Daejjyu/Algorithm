#include<iostream>

int N, R, C;

int ans;

void z(int size, int r, int c)
{
	if (size == 1)
		return;
	int nn = size / 2;
	if (r < nn && c < nn)
		z(nn, r, c);
	else if (r < nn && c >= nn) {
		ans += nn * nn;
		z(nn, r, c - nn);
	} else if (r >= nn && c < nn) {
		ans += nn * nn * 2;
		z(nn, r - nn, c);
	} else if (r >= nn && c >= nn) {
		ans += nn * nn * 3;
		z(nn, r - nn, c - nn);
	}
}

int main()
{
	scanf("%d %d %d", &N, &R, &C);

	int size = 1 << N;
	z(size, R, C);
	printf("%d", ans);
}