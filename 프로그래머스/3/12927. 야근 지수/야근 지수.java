import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for (int i = 0 ; i < works.length ; i++) {
            pq.add(works[i]);
        }
        
        
        while(n > 0) {
            int top = pq.poll();
            
            if (top <= 0) {
                break;
            }
            
            int next = pq.peek();
            
            int diff = Math.min(top-next+1, n);
            n -= diff;
            pq.add(top - diff);
        }
        while(!pq.isEmpty()) {
            int top = pq.poll();
            
            if (top<= 0) {
                break;
            }
            answer += (long)top * (long)top;
        }
        
        return answer;
    }
}