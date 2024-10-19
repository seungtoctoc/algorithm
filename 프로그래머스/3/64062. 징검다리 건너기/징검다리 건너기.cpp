#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool canPass (vector<int> stones, int result, int k) {
    int combo = 0;
    
    for (int i = 0 ; i < stones.size() ; i++) {
        if (stones[i] - result > 0) {
            combo = 0;
            continue;
        }
        
        combo ++;
        
        if (combo >= k) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = 200'000'000;
    
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        
        if (canPass(stones, mid, k)) {
            left = mid;
            continue;
        }
        
        right = mid;
    }
    
    return left + 1;
}



