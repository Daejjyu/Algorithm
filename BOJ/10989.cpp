#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int const MAX = 10000 + 1;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int min = 10000, max = 0;

	int d;
	while (n--) {
		cin >> d;
		if (d > max)
			max = d;
		if (d < min)
			min = d;
		arr[d]++;
	}

	for (int i = min; i <= max; i++)
	{
		while (arr[i]--)
			cout << i << "\n";
	}
}