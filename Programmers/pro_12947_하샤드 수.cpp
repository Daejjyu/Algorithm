#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int digitSum = 0, n = x;
    while(n){        
        digitSum +=n%10;
        n/=10;
    }    
    return !bool(x%digitSum);
}