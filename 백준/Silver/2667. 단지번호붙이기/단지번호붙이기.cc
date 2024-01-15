#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25]={};
vector<int> v;
queue<pair<int,int>>q;

void BFS(int px, int py, int n){
    q.push(make_pair(px,py));
    map[px][py]=0;
    int cnt=0;
    
    while(!q.empty()){
        cnt++;
        int x,y;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(y+1<n &&map[x][y+1]==1){
            q.push(make_pair(x,y+1));
            map[x][y+1]=0;
        }
        if(y>0 && map[x][y-1]==1){
            q.push(make_pair(x,y-1));
            map[x][y-1]=0;
        }
        if(x+1<n && map[x+1][y]==1){
            q.push(make_pair(x+1,y));
            map[x+1][y]=0;
        }
        if(x>0 && map[x-1][y]==1){
            q.push(make_pair(x-1,y));
            map[x-1][y]=0;
        }
        
        
    }
    
    
    v.push_back(cnt);
}


int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1){
                BFS(i,j,n);
                
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout<<v.size()<<endl;
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    
    
}
