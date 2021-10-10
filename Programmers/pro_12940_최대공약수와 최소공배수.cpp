#include <string>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    int r=1;
    while(b){
        r = a % b;
        a = b;
        b = r;       
    }
    return a;
}

vector<int> solution(int n, int m) {    
    vector<int> answer;
    int gcd = getGcd(n,m);
    answer.push_back(gcd);
    answer.push_back(n*m/gcd);
    return answer;
}