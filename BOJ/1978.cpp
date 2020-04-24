#include <iostream>

const int MAX = 100001;
int arr[MAX] = { -2,-1,0 }; // -1 이면 소수X

void eratoChe()
{
	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] == 0) {
			for (int j = 2; i*j < MAX; j++)
			{
				arr[i*j] = -1;
			}
		}
	}
}

int main(void)
{
	eratoChe();

	int n;
	scanf("%d", &n);

	int cnt = 0;
	while (n--) {
		int d;
		scanf("%d", &d);
		if (arr[d] != -1) cnt++;
	}

	printf("%d", cnt);
}