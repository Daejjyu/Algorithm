#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char c;
	while (~scanf("%c", &c)) {
		int d = (int)c;

		if ('a' <= c && c <= 'z') {
			d += 13;
			int hi = int('z');
			if (d > hi)
				d -= 26;
		} else if ('A' <= c && c <= 'Z') {
			d += 13;
			int hi = int('Z');
			if (d > hi)
				d -= 26;
		}
		printf("%c", (char)d);
	}
}