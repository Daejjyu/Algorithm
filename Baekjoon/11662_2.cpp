#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double x[4], y[4];

double dist(double p)
{
	double posX1 = x[0] + (x[1] - x[0])*(p / 100);
	double posX2 = x[2] + (x[3] - x[2])*(p / 100);
	double posY1 = y[0] + (y[1] - y[0])*(p / 100);
	double posY2 = y[2] + (y[3] - y[2])*(p / 100);

	return (posX2 - posX1)*(posX2 - posX1) + (posY2 - posY1)*(posY2 - posY1);
}

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf %lf", x + i, y + i);
	}

	double lo = 0, hi = 100;
	while (hi - lo >= 1e-6) {
		double left = (2 * lo + hi) / 3;
		double right = (lo + 2 * hi) / 3;

		dist(left) > dist(right) ? lo = left : hi = right;
	}

	printf("%.10lf", sqrt(dist(hi)));
}