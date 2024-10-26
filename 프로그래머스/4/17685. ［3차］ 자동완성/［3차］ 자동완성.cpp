#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    
    vector<string> sorted_words = words;
    sort(sorted_words.begin(), sorted_words.end());
    
    int same[100'000] = {};
    
    for (int i = 0 ; i < sorted_words.size() - 1 ; i++) {
        int cnt = 0;
        
        while (cnt < min(sorted_words[i].size(), sorted_words[i+1].size()) && sorted_words[i][cnt] == sorted_words[i+1][cnt]) {
            cnt++;
        }
        
        same[i] = cnt;
    }
    
    for (int i = 0 ; i < sorted_words.size() ; i++) {
        int same_with_prev = 0;
        int same_with_next = 0;
        
        if (i - 1 >= 0) {
            same_with_prev = same[i - 1];
        }
        if (i + 1 < sorted_words.size()) {
            same_with_next = same[i];
        }
        
        int current_answer = max(same_with_prev, same_with_next);
        if (current_answer < sorted_words[i].size()) {
            current_answer++;
        }
        
        answer += current_answer;
    }
    
    return answer;
}