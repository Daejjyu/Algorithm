#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {    
    int R = arr1.size();
    int C = arr1[0].size();
    vector<vector<int>> answer;
    for(int i=0; i<R; i++){
        vector<int> elem;
        for(int j=0; j<C; j++){
            elem.push_back(arr1[i][j]+arr2[i][j]);   
        }
        answer.push_back(elem);
    }
    return answer;
}