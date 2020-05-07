#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int arr[500];
vector<pair<int, double>> prob;

bool cmp(pair<int, double> a, pair<int, double> b)
{
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++)
	{
		arr[stages[i] - 1]++;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}

	double group = stages.size();
	printf("group %lf\n", group);
	for (int i = 0; i < N; i++)
	{
		double fail = arr[i] / group;

		prob.push_back(make_pair(i, arr[i] / group));
		group -= arr[i];
	}

	sort(prob.begin(), prob.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		answer.push_back(prob[i].first + 1);
	}

	return answer;
}