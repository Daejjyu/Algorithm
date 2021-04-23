#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char day[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int a, b;
	scanf("%d %d", &a, &b);
	int daySum = 0;
	a--;
	while (a--) {
		daySum += month[a];
	}
	daySum += b;
	printf("%s", day[daySum % 7]);
}