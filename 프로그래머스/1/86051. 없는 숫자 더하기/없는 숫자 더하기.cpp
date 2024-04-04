#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int result = 0;
    
    for (int i = 1 ; i <= 9 ; i++) {
        result += i;
    }
    
    for (int i = 0 ; i < numbers.size() ; i++) {
        result -= numbers[i];
    }
    
    return result;
}