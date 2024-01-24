import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static long[] dp = new long[10_001];
    static int limit;

    public static void main(String[] args){
        int times = getTimes();
        initArray();

        for (int i = 0 ; i < times ; i++) {
            int num = scanner.nextInt();
            System.out.println(getValue(num));
        }
    }

    static int getTimes() {
        return scanner.nextInt();
    }

    static void initArray() {
        for (int i = 1 ; i <= 5; i++) {
            dp[i] = i;
        }
        limit = 5;
    }

    static long getValue(int num) {
        while(limit < num) {
            limit++;
            dp[limit] = dp[limit - 3] + dp[limit - 2] - dp[limit - 5] + 1;
        }

        return dp[num];
    }
}