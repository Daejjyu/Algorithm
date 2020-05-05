#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x[4], y[4];

double dist(double pos)
{
	double xD = ((x[2] + (x[3] - x[2])*(pos / 100)) - (x[0] + (x[1] - x[0])*(pos / 100)));
	double yD = ((y[2] + (y[3] - y[2])*(pos / 100)) - (y[0] + (y[1] - y[0])*(pos / 100)));

	return xD * xD + yD * yD;
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf %lf", x + i, y + i);
	}

	double fp = 0, lp = 100, minDist;

	while (lp - fp >= 1e-3) {////////-3?
		double lo = (2 * fp + lp) / 3;
		double hi = (fp + 2 * lp) / 3;
		double fDist = dist(lo);
		double lDist = dist(hi);
		minDist = min(fDist, lDist);
		fDist > lDist ? fp = lo : lp = hi;
	}
	printf("%.10lf", sqrt(minDist));
}