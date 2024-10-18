#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(4);
int vis[1'000'001]={};
vector<int> graph[1'000'001];
int in[1'000'001]={};

void getMainNode(vector<vector<int>> edges) {
    for (int i = 0 ; i < edges.size() ; i++) {
        in[edges[i][1]]++;
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    for (int i = 1 ; i <= 1'000'000; i++) {
        if (in[i] == 0 && graph[i].size() >= 2) {
            answer[0] = i;
            return;
        }
    }
}

void dfs(int now) {
    vis[now] = 1;
    
    if (graph[now].size() >= 2 && in[now] >= 2) {
        answer[3]++;
        return;
    }
    
    if (graph[now].size() == 0) {
        answer[2]++;
        return;
    }
    
    for (int i = 0 ; i < graph[now].size(); i++) {
        if (vis[graph[now][i]] > 0) {
            answer[1]++;
            return;
        }
        dfs(graph[now][i]);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    getMainNode(edges);
    
    for (int i = 0 ; i < graph[answer[0]].size() ; i++) {
        dfs(graph[answer[0]][i]);
    }
    
    return answer;
}