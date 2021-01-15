#include<iostream>
#include<list>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	list<int> list;
	for (int i = 0; i < N; i++)
	{
		list.push_back(i + 1);
	}

	auto it = list.begin();

	int cnt = 1;
	printf("<");
	while (!list.empty()) {
		if (cnt == K) {
			cnt = 1;
			if (list.size() == 1) {
				printf("%d>", *it);
				break;
			} else {
				if (it != --list.end()) {
					printf("%d, ", *it);
					it = list.erase(it);
				} else {
					printf("%d, ", *it);
					list.erase(--list.end());
					it = list.begin();
				}
			}
		} else {
			if (it == --list.end())
				it = list.begin();
			else
				it++;
			cnt++;
		}
	}
}