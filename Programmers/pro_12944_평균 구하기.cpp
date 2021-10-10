#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0, N=arr.size();
    for(int i=0; i<N; i++){
        sum+=arr[i];
    }       
    return double(sum)/N;
}