import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        int input[] = getInput();
        System.out.println(getAnswer(input));
    }

    static int[] getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int top = Integer.parseInt(st.nextToken());
        int display = Integer.parseInt(st.nextToken());
        int reversalLimit = Integer.parseInt(st.nextToken());
        int now = Integer.parseInt(st.nextToken());

        int[] input = {top, display, reversalLimit, now};

        return input;
    }

    static int getAnswer(int[] input) {
        int top = input[0];
        int display = input[1];
        int reversalLimit = input[2];
        int now = input[3];

        int nowDisplay[] = getDisplayArray(now, display);
        int answer = 0;

        for (int i = 1 ; i <= top ; i++) {
            int currentNumDisplay[] = getDisplayArray(i, display);

            int reversal = 0;
            for (int j = 0 ; j < display ; j++) {
                reversal += getReversal(nowDisplay[j], currentNumDisplay[j]);
            }

            if (reversal <= reversalLimit) {
                answer++;
            }
        }

        return answer - 1;
    }

    static int[] getDisplayArray(int num, int display) {
        int result[] = new int[display];
        int div = (int) Math.pow(10, display - 1);
        int i = 0;
        while(div > 0) {
            result[i++] = num / div;
            num %= div;
            div /= 10;
        }

        return result;
    }

    static int getReversal(int n1, int n2) {
        //     0
        //   1   2
        //     3
        //   4   5
        //     6

        int[][] num = {
                {1, 1, 1, 0, 1, 1, 1},  // 0
                {0, 0, 1, 0, 0, 1, 0},  // 1
                {1, 0, 1, 1, 1, 0, 1},  // 2
                {1, 0, 1, 1, 0, 1, 1},  // 3
                {0, 1, 1, 1, 0, 1, 0},  // 4
                {1, 1, 0, 1, 0, 1, 1},  // 5
                {1, 1, 0, 1, 1, 1, 1},  // 6
                {1, 0, 1, 0, 0, 1, 0},  // 7
                {1, 1, 1, 1, 1, 1, 1},  // 8
                {1, 1, 1, 1, 0, 1, 1},  // 9
        };

        int result = 0;

        for (int i = 0 ; i <= 6 ; i++) {
            if (num[n1][i] != num[n2][i]) {
                result++;
            }
        }

        return result;
    }
}