#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
int dp[2'001][2'001] = {};

int check(int s, int e) {   
    if (dp[s][e] == 1) {
        return 1;
    }
    
    if (s == e) {
        return 1;
    }
    
    if (s + 1 == e && numbers[s] == numbers[e]) {
        return dp[s][e] = 1;
    }
    
    if (numbers[s] == numbers[e]) {
        return dp[s][e] = check(s + 1, e - 1);
    }
    
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    numbers.push_back(0);
    for (int i = 0 ; i < n ; i++) {
        int num;
        scanf("%d", &num);
        
        numbers.push_back(num);
    }
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0 ; i < m ; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        
        printf("%d\n", check(s, e));
    }
}