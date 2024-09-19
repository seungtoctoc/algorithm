class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        int[][] map = new int[100][100];
        int[][] dp = new int[100][100];
        
        for (int i = 0 ; i < puddles.length ; i++) {
            // System.out.println(puddles[i][0] + " " + puddles[i][1]);
            map[puddles[i][1]-1][puddles[i][0]-1] = -1;
        }
        
        for (int i = 0 ; i < n ; i++) {
            if (map[i][0] == -1) {
                break;
            }
            dp[i][0] = 1;
        }
        
        for (int i = 0 ; i < m ; i++) {
            if (map[0][i] == -1) {
                break;
            }
            dp[0][i] = 1;
        }
        
        for (int i = 1 ; i < n ; i++) {
            for (int j = 1 ; j < m ; j++) {
                if (map[i][j] == -1) {
                    continue;
                }
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
        
        
        // for (int i = 0 ; i< n ; i++) {
        //     for (int j = 0 ; j < m ; j++) {
        //         System.out.print(dp[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        
        answer = dp[n-1][m-1];
        return answer;
    }
}