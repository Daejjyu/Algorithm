#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	cin >> N >> M;
	if (N == 1)
		cout << 1 << endl;
	else if (N == 2)
		cout << min(4, (M + 1) / 2) << endl;
	else if (N >= 3) {
		if (M <= 6)
			cout << min(4, M) << endl;
		else
			cout << M - 2 << endl;
	}
}