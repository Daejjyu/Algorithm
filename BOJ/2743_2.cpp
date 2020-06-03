#include <iostream>

int main()
{
	char c;
	int ans = 0;
	while (~scanf("%c", &c)) {
		ans++;
	}
	printf("%d", ans - 1);
}