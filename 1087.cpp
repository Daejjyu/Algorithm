#include<iostream>
#include<algorithm>
using namespace std;

int N;
double x[50], y[50], vx[50], vy[50];

double size(double time)
{
	double maxX = -1e9, maxY = -1e9;
	double minX = 1e9, minY = 1e9;

	for (int i = 0; i < N; i++)
	{
		double posX = x[i] + vx[i] * time;
		double posY = y[i] + vy[i] * time;
		maxX = max(posX, maxX);	minX = min(posX, minX);
		maxY = max(posY, maxY);	minY = min(posY, minY);
	}
	return max(maxX - minX, maxY - minY);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf %lf %lf %lf", x + i, y + i, vx + i, vy + i);
	}

	double lo = 0, hi = 1e9;
	for (int i = 0; i < 200; i++)
	{
		double p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (size(p) < size(q)) hi = q;
		else lo = p;
	}
	printf("%.10lf\n", size(lo));
}