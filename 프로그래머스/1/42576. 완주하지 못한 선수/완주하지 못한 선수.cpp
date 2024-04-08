#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int>compMap;
    string ans;
    
    for (int i = 0 ; i < completion.size() ; i++) {
        compMap[completion[i]]++;
    }
    
    for (int i = 0 ; i < participant.size() ; i++) {
       if (compMap[participant[i]] == 0) {
           return participant[i];
           break;
       }
        
        compMap[participant[i]]--;
    }
}