#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> formatted_record;
    map<string, string> user;
    
    for(int i = 0 ; i < record.size() ; i++) {
        stringstream ss(record[i]);
        vector<string> current_record;
        string record_word;
        
        while (getline(ss, record_word, ' ')) {
            current_record.push_back(record_word);
            
        }
        formatted_record.push_back(current_record);
        
        if (current_record[0] == "Leave") {
            continue;
        }
        
        user[current_record[1]] = current_record[2];        
    }
    
    for (int i = 0 ; i < formatted_record.size() ; i++) {
        string type = formatted_record[i][0];
        string userId = formatted_record[i][1];
        string message;
        
        if (type == "Change"){
            continue;
        }
        
        if (type == "Enter") {
            message = user[userId] + "님이 들어왔습니다.";
        }
        else {
            message = user[userId] + "님이 나갔습니다.";
        }
        
        answer.push_back(message);
    }
    
    return answer;
}