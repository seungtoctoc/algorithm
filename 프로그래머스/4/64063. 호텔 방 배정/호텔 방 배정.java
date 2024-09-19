import java.util.*;

class Solution {
    Map<Long, Long> rooms = new HashMap<>();
        
    long getRoom(long want) {
        if (!rooms.containsKey(want)) {
            rooms.put(want, want+1);
            return want;
        }
        
        long room = getRoom(rooms.get(want));
        rooms.put(want, room);
        return room;
    }
    
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        
        for (int i = 0 ; i < room_number.length ; i++) {
            answer[i] = getRoom(room_number[i]);
        }
        
        
        return answer;
    }
}