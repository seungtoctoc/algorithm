#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> sorted_words;
map<int, vector<string>> words_of_size;

vector<string> reversed_words;
map<int, vector<string>> reversed_words_of_size;

void init(vector<string> words) {
    sorted_words = words;
    reversed_words = words;
    
    sort(sorted_words.begin(), sorted_words.end());
    
    for (int i = 0 ; i < sorted_words.size() ; i++) {
        words_of_size[sorted_words[i].size()].push_back(sorted_words[i]);
        reverse(reversed_words[i].begin(), reversed_words[i].end());
    }
    
    sort(reversed_words.begin(), reversed_words.end());
    
    for (string word: reversed_words) {
        reversed_words_of_size[word.size()].push_back(word);
    }
}

int getResult(string query) {
    if (query.front() == '?' && query.back() == '?') {
        return words_of_size[query.size()].size();
    }
    
    string min_str = query;
    string max_str = query;
    
    for (int i = 0 ; i < query.size() ; i++) {
        if (query[i] == '?') {
            min_str[i] = 'a';
            max_str[i] = 'z';
        }
    }
    
    if (query.back() == '?') {
        int lo = lower_bound(words_of_size[query.size()].begin(), words_of_size[query.size()].end(), min_str) - words_of_size[query.size()].begin();
        int up = upper_bound(words_of_size[query.size()].begin(), words_of_size[query.size()].end(), max_str) - words_of_size[query.size()].begin();
        
        // cout<<"--?? // "<<min_str<<" "<<lo<<" // "<<max_str<<" "<<up<<endl;
        
        return up - lo;
    }
    
    reverse(min_str.begin(), min_str.end());
    reverse(max_str.begin(), max_str.end());
    
    int lo = lower_bound(reversed_words_of_size[query.size()].begin(), reversed_words_of_size[query.size()].end(), min_str) - reversed_words_of_size[query.size()].begin();
    int up = upper_bound(reversed_words_of_size[query.size()].begin(), reversed_words_of_size[query.size()].end(), max_str) - reversed_words_of_size[query.size()].begin();
        
    // cout<<"??-- // "<<min_str<<" "<<lo<<" // "<<max_str<<" "<<up<<endl;
    
    return up - lo;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<string, int> results;

    init(words);
    
    for (string query: queries) {
        if (!results[query]) {
            results[query] = getResult(query);
        }   
        answer.push_back(results[query]);
    }
    
    return answer;
}