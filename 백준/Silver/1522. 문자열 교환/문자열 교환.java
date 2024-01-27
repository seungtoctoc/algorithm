import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] input = getInput();
        int totalA = countTotalA(input);
        int answer = getAnswer(input, totalA);
        System.out.println(answer);
    }

    static String[] getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputLine = br.readLine();

        String[] input = inputLine.split("");

        return input;
    }

    static int countTotalA(String[] input) {
        int totalA = 0;
        for (int i = 0 ; i < input.length ; i++) {
            if (input[i].charAt(0) == 'a') {
                totalA++;
            }
        }

        return totalA;
    }
    static int getAnswer(String[] input, int totalA) {
        int start = 0;
        int end = totalA - 1;

        int cntA = 0;
        int cntB = 0;

        // init
        for (int i = 0 ; i <= end ; i++) {
            if (input[i].charAt(0) == 'a') {
                cntA++;
                continue;
            }
            cntB++;
        }

        int answer = cntB;

        // moving
        while (start + 1 < input.length) {
            start++;
            end = (end + 1) % input.length;

            if (input[start - 1].charAt(0) == 'a') {
                cntA--;
            }
            else {
                cntB--;
            }

            if (input[end].charAt(0) == 'a') {
                cntA++;
            }
            else {
                cntB++;
            }

            answer = Math.min(answer, cntB);
        }

        return answer;
    }
}