#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long longNum = num;
    while(longNum>1 and answer++<500){
        if(longNum%2){
            longNum=longNum*3+1;
        }else{
            longNum/=2;
        }        
    }
    return answer<500 ? answer : -1;
}