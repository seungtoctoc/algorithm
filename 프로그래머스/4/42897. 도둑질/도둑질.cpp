#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    // steal first house
    int dp1[1'000'000]={};
    // not steal first house
    int dp2[1'000'000]={};
    
    dp1[0] = money[0];
    dp2[1] = money[1];
    
    for(int i = 1 ; i < money.size() - 1 ; i++) {
        int prev2 = 0;
        if (i - 2 >= 0) {
            prev2 = dp1[i - 2];
        }
        
        int prev3 = 0;
        if (i - 3 >= 0) {
            prev3 = dp1[i - 3];
        }
        
        dp1[i] = max(prev2 + money[i], prev3 + money[i]);
        answer = max(answer, dp1[i]);
    }
    
    for (int i = 2 ; i < money.size() ; i++) {
        int prev2 = 0;
        if (i - 2 >= 0) {
            prev2 = dp2[i - 2];
        }
        
        int prev3 = 0;
        if (i - 3 >= 0) {
            prev3 = dp2[i - 3];
        }
        
        dp2[i] = max(prev2 + money[i], prev3 + money[i]);
        answer = max(answer, dp2[i]);
    }
    
    return answer;
}