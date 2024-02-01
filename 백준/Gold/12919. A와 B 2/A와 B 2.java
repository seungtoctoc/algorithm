import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;


public class Main {
    static String stringA;
    static String stringB;
    static String stringBR;

    public static void main(String[] args) throws IOException {
        getInput();
        System.out.println(getAnswer());
    }

    static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        stringA = br.readLine();
        stringB = br.readLine();

        for (int i = stringB.length() - 1 ; i >= 0 ; i--) {
            stringBR += stringB.charAt(i);
        }
    }

    static int getAnswer() {
        Queue<String> queue = new LinkedList<>();

        if (isInclude(stringA, stringB) || isInclude(stringA, stringBR)) {
            queue.add(stringA);
        }

        while (!queue.isEmpty()) {
            String current = queue.poll();

            if (current.equals(stringB)) {
                return 1;
            }

            if (current.length() == stringB.length()) {
                continue;
            }

            String addA = current + 'A';
            if (isInclude(addA, stringB) || isInclude(addA, stringBR)) {
                queue.add(addA);
            }

            String reverse = getReverse(current + 'B');
            if (isInclude(reverse, stringB) || isInclude(reverse, stringBR)) {
                queue.add(reverse);
            }
        }
        return 0;
    }

    static String getReverse(String string) {
        String result = "";
        for (int i = string.length() - 1 ; i >= 0 ; i--) {
            result += string.charAt(i);
        }
        return result;
    }

    static boolean isInclude(String shortString, String longString) {
        for (int i = 0 ; i <= longString.length() - shortString.length() ; i++) {
            if (longString.charAt(i) == shortString.charAt(0)) {
                boolean result = true;
                for (int j = 1 ; j < shortString.length() ; j++) {
                    if (shortString.charAt(j) != longString.charAt(i + j)) {
                        result = false;
                        break;
                    }
                }

                if (result == true) {
                    return true;
                }
            }
        }

        return false;
    }
}