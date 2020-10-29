#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	map<string, int> map1;
	for (int i = 0; i < participant.size(); i++) {
		map1[participant[i]]++;
	}
	for (int i = 0; i < completion.size(); i++) {
		map1[completion[i]]--;
	}

	string answer = "";
	for (int i = 0; i < participant.size(); i++) {
		if (map1[participant[i]] > 0) {
			answer = participant[i];
			cout << answer << "\n";
		}
	}
	return answer;
}