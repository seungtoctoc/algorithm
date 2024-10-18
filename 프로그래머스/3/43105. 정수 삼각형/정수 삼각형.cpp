#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int dp[500][500]={};
    dp[0][0] = triangle[0][0];
    
    for(int i = 0 ; i + 1 < triangle.size(); i++) {
        for (int j = 0 ; j < triangle[i].size() ; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + triangle[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
            
            answer = max(answer, dp[i+1][j]);
            answer = max(answer, dp[i+1][j+1]);
        }
    }
    
    return answer;
}