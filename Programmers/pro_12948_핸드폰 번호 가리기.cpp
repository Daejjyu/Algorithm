#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int N = phone_number.length();
    string answer = "";
    for(int i=0; i<N-4; i++){
        answer+='*';
    }
    for(int i=N-4; i<N; i++){
        answer+=phone_number[i];
    }
    return answer;
}