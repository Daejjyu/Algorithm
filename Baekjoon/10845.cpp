#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	vector<int> arr;

	while (n--) {
		string s;
		cin >> s;

		if (s == "push")
		{
			int a;
			cin >> a;
			arr.push_back(a);
		} else if (s == "pop")
		{
			if (arr.size() != 0) {
				printf("%d\n", arr[0]);
				arr.erase(arr.begin());
			} else
				printf("-1\n");
		} else if (s == "size")
		{
			printf("%d\n", arr.size());
		} else if (s == "empty") {
			if (arr.size() != 0) {
				printf("0\n");
			} else printf("1\n");
		} else if (s == "front")
		{
			if (arr.size() != 0) {
				printf("%d\n", arr[0]);
			} else
				printf("-1\n");
		} else if (s == "back")
		{
			if (arr.size() != 0) {
				printf("%d\n", arr[arr.size() - 1]);
			} else
				printf("-1\n");
		}
	}
}