#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getCookies(vector<int> cookie, int m) {
    // cout<<"m: "<<m<<endl;
    int ans = 0;
    
    int left_idx = m;
    int right_idx = m + 1;
    
    int left_sum = cookie[m];
    int right_sum = cookie[m + 1];
    
    while(left_idx >= 0 && right_idx < cookie.size()) {
        // cout<<"idx: "<<left_idx<<" "<<right_idx<<", sum: "<<left_sum<<" "<<right_sum<<endl;
        if (left_sum == right_sum) {
            ans = max(ans, left_sum);
            
            left_sum += cookie[--left_idx];
            right_sum += cookie[++right_idx];
            continue;
        }
        
        if (left_sum < right_sum) {
            left_sum += cookie[--left_idx];
            continue;
        }
        
        right_sum += cookie[++right_idx];
    }
    
    return ans;
}

int solution(vector<int> cookie) {
    int answer = 0;
    
    for (int i = 0 ; i < cookie.size() - 1 ; i++) {
        answer = max(answer, getCookies(cookie, i));
    }
    
    return answer;
}