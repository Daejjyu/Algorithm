#include <iostream>

int main()
{
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	int ans = (V - B - 1) / (A - B) + 1;
	printf("%d", ans);
}