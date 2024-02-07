import java.io.IOException;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int[] testcases = getInput();

        for (int i = 0 ; i < testcases.length ; i++) {
            makeString(2, testcases[i], "1");
            sb.append("\n");
        }

        System.out.println(sb);
    }

    static int[] getInput() {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] testcases = new int[n];
        for (int i = 0 ; i < n ; i++) {
            int testcase = scanner.nextInt();
            testcases[i] = testcase;
        }

        return testcases;
    }

    static void makeString(int now, int num, String str) {
        if (now > num) {
            if (calculate(str) == 0) {
                sb.append(str + "\n");
            }
            return;
        }

        makeString(now + 1, num, str + " " + now);
        makeString(now + 1, num, str + "+" + now);
        makeString(now + 1, num, str + "-" + now);
    }

    static int calculate(String str) {
        String newStr = str.replace(" ", "");
        StringTokenizer st = new StringTokenizer(newStr,"+-");

        Queue<Character> signs = new LinkedList<>();
        for (int i = 0 ; i < str.length() ; i++) {
            if (str.charAt(i) == '+' || str.charAt(i) == '-') {
                signs.add(str.charAt(i));
            }
        }

        // sum = 1 로 init
        int sum = Integer.parseInt(st.nextToken());

        while(st.hasMoreTokens()) {
            int nextNum = Integer.parseInt(st.nextToken());
            char sign = signs.poll();

            if (sign == '+') {
                sum += nextNum;
                continue;
            }
            sum -= nextNum;
        }

        return sum;
    }
}