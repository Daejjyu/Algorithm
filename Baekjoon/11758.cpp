#include<iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	int ccw = x1 * y2 - y1 * x2 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1;
	if (ccw < 0)
		printf("%d", -1);
	else if (ccw > 0)
		printf("%d", 1);
	else
		printf("%d", 0);
}