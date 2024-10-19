#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int num;
    int x;
    int y;
};

vector<Node> nodes;
int edges[100'001][2] = {};

void initNodes(vector<vector<int>> nodeinfo) {
    for (int i = 0 ; i < nodeinfo.size() ; i++) {
        int node_num = i + 1;
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        
        Node current_node = {node_num, x, y};
        nodes.push_back(current_node);
    }
}

Node getRoot(vector<Node> nodes) {
    Node root = {-1, -1, -1};
    
    for (Node node : nodes) {
        if (node.y > root.y) {
            root.y = node.y;
            root.x = node.x;
            root.num = node.num;
        }
    }
    
    vector<Node> left_nodes;
    vector<Node> right_nodes;
    
    for (Node node : nodes) {
        if (node.y >= root.y) {
            continue;
        }
        
        if (node.x < root.x) {
            left_nodes.push_back(node);
            continue;
        }
        right_nodes.push_back(node);
    }
    
    if (left_nodes.size() > 0) {
        edges[root.num][0] = getRoot(left_nodes).num;
    }
    if (right_nodes.size() > 0) {
        edges[root.num][1] = getRoot(right_nodes).num;
    }
    
    return root;
}

vector<int> ans1;
vector<int> ans2;

void search1 (int now) {   
    ans1.push_back(now);
    
    if (edges[now][0] > 0) {
        search1(edges[now][0]);
    }
    
    if (edges[now][1] > 0) {
        search1(edges[now][1]);
    }
}

void search2 (int now) {
    if (edges[now][0] > 0) {
        search2(edges[now][0]);
    }
    
    if (edges[now][1] > 0) {
        search2(edges[now][1]);
    }
    
    ans2.push_back(now);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    initNodes(nodeinfo);
    
    Node root = getRoot(nodes);
    
    search1(root.num);
    search2(root.num);
    
    answer.push_back(ans1);
    answer.push_back(ans2);
    
    return answer;
}
