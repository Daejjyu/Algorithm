#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct _Student
{
	string name;
	int korea;
	int english;
	int math;
} student;

bool cmp(student a, student b)
{
	if (a.korea > b.korea)
		return true;
	if (a.korea == b.korea) {
		if (a.english < b.english)
			return true;
		if (a.english == b.english) {
			if (a.math > b.math)
				return true;
			if (a.math == b.math)
				if (a.name < b.name)
					return true;
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<student> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].korea >> arr[i].english >> arr[i].math;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << "\n";
	}
}