import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int[] sortedPeople = people;
        
        Arrays.sort(sortedPeople);
        
        int fattest = sortedPeople.length - 1;
        int lightest = 0;
        
        while (lightest <= fattest) {      
            if (sortedPeople[fattest] + sortedPeople[lightest] <= limit) {
                lightest++;
            }
            fattest--;
            answer++;
        }
        
        return answer;
    }
}