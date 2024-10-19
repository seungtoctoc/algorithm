#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int open, int close, int n) {
    if (open + close == 2 * n) {
        answer++;
        return;
    }
    
    if (open == close) {
        dfs(open + 1, close, n);
        return;
    }
    
    dfs(open, close + 1, n);
    
    if (open + 1 <= n) {
        dfs(open + 1, close, n);
    }
}

int solution(int n) {
    dfs(0, 0, n);
    return answer;
}