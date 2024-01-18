import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static double[][] map = new double[29][29];
    static double answer;
    static int n;
    static double[] prob = new double[4];
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) {
        n = scanner.nextInt();

        for (int i = 0 ; i < 4 ; i++) {
            int input = scanner.nextInt();

            prob[i] = (double) input / 100;
        }

        map[14][14] = 1;
        DFS(14, 14, 0);

        System.out.println(answer);
    }

    static void DFS(int x, int y, int time) {
        if (time == n) {
            answer += map[x][y];
            return;
        }

        for (int i = 0 ; i < 4 ; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (map[nextX][nextY] == 0 && prob[i] > 0) {
                map[nextX][nextY] = map[x][y] * prob[i];
                DFS(nextX, nextY, time + 1);
                map[nextX][nextY] = 0;
            }
        }
    }
}