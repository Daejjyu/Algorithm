#include <iostream>
#include <vector>
using namespace std;

vector<char> arr;

int main()
{
	int N, B;
	scanf("%d %d", &N, &B);

	while (N) {
		int temp = N % B;
		if (temp >= 10)
			arr.push_back('A' + temp - 10);
		else
			arr.push_back(temp + '0');
		N /= B;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		printf("%c", arr[arr.size() - 1 - i]);
	}
}