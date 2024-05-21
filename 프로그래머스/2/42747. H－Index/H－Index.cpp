#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort (citations.begin(), citations.end());
    
//     for (auto i : citations) {
//         cout <<i<<" ";
//     }
    
    if (citations[0] >= citations.size()) {
        return citations.size();
    }

    for (int i = 0 ; i < citations.size() - 1 ; i++) {
        if (citations[i+1] == citations[i]) {
            continue;
        }
        
        if (citations[i+1] >= citations.size() - i - 1) {
            return citations.size() - i - 1;
        }
    }
    
    if (citations.back() > 0) {
        return 1;
    }
    
    return 0;
}