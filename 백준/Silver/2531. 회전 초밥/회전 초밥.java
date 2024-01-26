import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer> dish = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        int[] input = getInput();
        System.out.println(getMaxType(input));
    }

    static int[] getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int dishNum = Integer.parseInt(st.nextToken());
        int typeNum = Integer.parseInt(st.nextToken());
        int combo = Integer.parseInt(st.nextToken());
        int coupon = Integer.parseInt(st.nextToken());

        for (int i = 0 ; i < dishNum ; i++) {
            int type = Integer.parseInt(br.readLine());
            dish.add(type);
        }

        for (int i = 0 ; i < combo ; i++) {
            dish.add(dish.get(i));
        }

        int[] input = {typeNum, combo, coupon};
        return input;
    }

    static int getMaxType(int[] input) {
        int typeNum = input[0];
        int combo = input[1];
        int coupon = input[2];

        int start = 0;
        int end = combo - 1;

        int[] count = new int[typeNum + 1];
        int duplicate = 0;

        // init
        for (int i = 0 ; i <= end ; i++) {
            int type = dish.get(i);
            count[type]++;

            if (count[type] > 1) {
                duplicate++;
            }
        }

        int answer = combo - duplicate;
        if (count[coupon] == 0) {
            answer++;
        }

        while (end + 1 < dish.size()) {
            int startType = dish.get(start);
            count[startType]--;
            if (count[startType] > 0) {
                duplicate--;
            }
            start++;

            end++;
            int endType = dish.get(end);
            count[endType]++;
            if (count[endType] > 1) {
                duplicate++;
            }

            int val = combo - duplicate;
            if (count[coupon] == 0) {
                val++;
            }

            answer = Math.max(answer, val);
        }

        return answer;
    }
}