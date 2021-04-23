#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size());
	stack<int> st;
	for (int i = 0; i < prices.size(); i++) {
		while (!st.empty() && prices[st.top()] > prices[i]) {
			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		answer[st.top()] = prices.size() - 1 - st.top();
		st.pop();
	}
	return answer;
}