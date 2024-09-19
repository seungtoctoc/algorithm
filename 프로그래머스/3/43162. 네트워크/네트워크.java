class Solution {
    int[] vis = new int[200];
    int[][] network;
    
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        network = computers;
        
        for (int i = 0 ; i < n ; i++) {
            if (vis[i] == 0) {
                answer++;
                dfs(i);
            }
        }
        
        
        return answer;
    }
    
        void dfs(int now) {
        System.out.println(now);
        vis[now] = 1;
        
        for (int i = 0 ; i < network[now].length; i++) {
            if (network[now][i] == 1 && vis[i] == 0) {
                System.out.println("dfs" + i);
                
                dfs(i);
            }
        }
    }
}