import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        ArrayList<Integer> values = new ArrayList<>();

        for (int i = 0 ; i < n ; i++) {
            int value = scanner.nextInt();
            values.add(value);
        }

        int first = 0;
        int second = values.size() - 1;

        int min = 2_000_000_000;
        int minFirst = -1;
        int minSecond = -1;

        while (first < second) {
            int result = values.get(first) + values.get(second);

            if (Math.abs(result) < min) {
                min = Math.abs(result);
                minFirst = first;
                minSecond = second;
            }

            if (result == 0) {
                break;
            }

            if (result > 0) {
                second--;
                continue;
            }

            if (result < 0) {
                first++;
            }
        }

        System.out.println(values.get(minFirst) + " " + values.get(minSecond));
    }
}