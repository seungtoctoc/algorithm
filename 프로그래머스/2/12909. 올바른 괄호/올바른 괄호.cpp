#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int temp = 0 ;
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '(') {
            temp ++;
            continue;
        }
        
        temp --;
        
        if (temp < 0) {
            return false;
        }
    }
    
    if (temp == 0) {
        return true;
    }
    return false;
}