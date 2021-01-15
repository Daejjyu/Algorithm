#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[100000];
	int count = 0;
	int index = 0;

	int n;
	cin >> n;

	string s;
	int value;

	while (n--) {
		cin >> s;
		if (s == "push") {
			cin >> value;
			arr[count++] = value;
		}
		if (s == "top")
			if (count == 0)
				cout << -1 << "\n";
			else
				cout << arr[count - 1] << "\n";
		if (s == "size")
			cout << count << "\n";
		if (s == "pop")
			if (count == 0)
				cout << -1 << "\n";
			else {
				cout << arr[(count - 1)] << "\n";
				count--;
			}
		if (s == "empty")
			if (count == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
	}
}