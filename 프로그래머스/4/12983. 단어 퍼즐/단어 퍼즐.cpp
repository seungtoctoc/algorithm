#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int dp[20'000] = {};
    memset(dp, -1, sizeof(dp));
    vector<string> sorted_strs = strs;
    sort(sorted_strs.begin(), sorted_strs.end());
    
    for (int i = 0 ; i < t.size() ; i++) {
        int prev = 0;
        if (i-1 >= 0 && dp[i-1] == -1) {
            continue;
        }
        prev = dp[i-1];
        
        for (int j = 1 ; j <= 5 ; j++) {
            if (i + j > t.size()) {
                break;
            }
            
            string target = t.substr(i, j);
            // cout<<"target: "<<target<<endl;
            
            if (binary_search(sorted_strs.begin(), sorted_strs.end(), target)) {
                if (dp[i+j-1] == -1) {
                    dp[i+j-1] = prev + 1;
                }
                else {
                    dp[i + j - 1] = min(dp[i + j - 1], prev + 1);
                }
            }
        }
    }
    
    // for (int i = 0 ; i < t.size() ; i++) {
    //     cout<<dp[i]<<" ";
    // }
    
    return dp[t.size() - 1];
}