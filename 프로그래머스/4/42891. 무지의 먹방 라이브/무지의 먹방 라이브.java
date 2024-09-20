import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        long extraMove = k;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i: food_times) {
            pq.add(i);
        }
        
        int lastTime = 0;

        while(!pq.isEmpty() && ((long)pq.peek() - lastTime) * pq.size() <= extraMove) {
            extraMove -= ((long)pq.peek() - lastTime) * pq.size();
            lastTime = pq.poll();
        }
        
        if (pq.isEmpty()) {
            return -1;
        }
        
        extraMove %= pq.size();

        for (int i = 0 ; i < food_times.length ; i++) {
            if (food_times[i] <= lastTime) {
                continue;
            }
            
            if (extraMove == 0) {
                return i + 1;
            }
            extraMove --;
        }
        
        return 0;
    }
}