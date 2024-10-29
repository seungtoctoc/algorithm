#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(int distance, vector<int> sorted_rocks, int n, int min_distance) {
    int prev = 0;
    int pass = 0;
    
    sorted_rocks.push_back(distance);
    
    for (int i = 0 ; i < sorted_rocks.size() ; i++) {
        if (sorted_rocks[i] - prev < min_distance) {
            pass++;
            
            if (pass > n) {
                return false;
            }
            
            continue;
        }
        
        prev = sorted_rocks[i];
    }
    
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    vector<int> sorted_rocks = rocks;
    sort(sorted_rocks.begin(), sorted_rocks.end());
    
    if (rocks.size() == n) {
        return distance;
    }

    int left = 0;
    int right = distance;
    
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        
        if (check(distance, sorted_rocks, n, mid)) {
            left = mid;  
            continue;
        }
        right = mid;
    }
    
    return left;
}