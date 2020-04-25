#include <iostream>

int main(void)
{
	int n;
	scanf("%d", &n);
	int cnt2 = 0, cnt5 = 0;
	n++;
	while (n--) {
		int d = n;
		while (d) {
			if (d % 2 == 0) {
				d /= 2;
				cnt2++;
			} else if (d % 5 == 0) {
				d /= 5;
				cnt5++;
			} else break;
		}
	}
	int cnt = 0;
	if (cnt2 > 0 && cnt5 > 0)
		cnt2 > cnt5 ? cnt = cnt5 : cnt = cnt2;

	printf("%d", cnt);
}