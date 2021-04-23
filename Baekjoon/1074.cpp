#include <iostream>

int ans;

void visit(int r, int c, int n)
{
	if (n == 1) {
		return;
	} else {
		int nn = n / 2;
		if (r < nn && c < nn) {
			ans += 0;
			visit(r, c, nn);
		}
		if (r < nn && c >= nn) {
			ans += nn * nn;
			visit(r, c - nn, nn);
		}
		if (r >= nn && c < nn) {
			ans += nn * n;
			visit(r - nn, c, nn);
		}
		if (r >= nn && c >= nn) {
			ans += nn * nn * 3;
			visit(r - nn, c - nn, nn);
		}
	}
}
int main(void)
{
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	int num = (1 << N);
	visit(r, c, num);
	printf("%d", ans);
}