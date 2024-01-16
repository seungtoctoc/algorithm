import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while(true) {
            Pos inputSize = getSize();

            if (inputSize.isEnd()) {
                break;
            }

            char[][][] building = new char[32][32][32];
            Pos startPos = getBuilding(inputSize, building);

            int answer = BFS(startPos, building);

            if (answer > 0) {
                System.out.println("Escaped in " + answer + " minute(s).");
                continue;
            }

            System.out.println("Trapped!");
        }


    }

    static Pos getSize() {
        String input = scanner.nextLine();

        String[] numbers = input.split(" ");

        int l = Integer.parseInt(numbers[0]);
        int r = Integer.parseInt(numbers[1]);
        int c = Integer.parseInt(numbers[2]);

        Pos inputSize = new Pos(l, r, c);
        return inputSize;
    }

    static Pos getBuilding(Pos inputSize, char[][][] building) {
        Pos startPos = new Pos(0, 0, 0);

        for (int i = 1 ; i <= inputSize.getL() ; i++) {
            for (int j = 1 ; j <= inputSize.getR() ; j++) {
                String inputLine = scanner.nextLine();
                String[] strArray = inputLine.split("");

                for (int k = 1 ; k <= inputSize.getC() ; k++) {
                    building[i][j][k] = strArray[k - 1].charAt(0);

                    if (building[i][j][k] == 'S') {
                        startPos.setPos(i, j, k);
                    }
                }
            }
            scanner.nextLine();
        }

        return startPos;
    }

    static int BFS(Pos startPos, char[][][] building) {
        int[] dl = {-1, 1, 0, 0, 0, 0};
        int[] dr = {0, 0, -1, 1, 0, 0};
        int[] dc = {0, 0, 0, 0, -1, 1};

        Queue<Pos> queue = new LinkedList<>();
        queue.add(startPos);

        int[][][] visit = new int[32][32][32];
        int startL = startPos.getL();
        int startR = startPos.getR();
        int startC = startPos.getC();
        visit[startL][startR][startC] = 1;

        while (!queue.isEmpty()) {
            Pos currentPos = queue.poll();

            int currentL = currentPos.getL();
            int currentR = currentPos.getR();
            int currentC = currentPos.getC();

            for (int i = 0 ; i < 6 ; i++) {
                int nextL = currentL + dl[i];
                int nextR = currentR + dr[i];
                int nextC = currentC + dc[i];

                if (building[nextL][nextR][nextC] == '.' && visit[nextL][nextR][nextC] == 0) {
                    visit[nextL][nextR][nextC] = visit[currentL][currentR][currentC] + 1;
                    Pos nextPos = new Pos(nextL, nextR, nextC);
                    queue.add(nextPos);

                    continue;
                }

                if (building[nextL][nextR][nextC] == 'E') {
                    return visit[currentL][currentR][currentC];
                }
            }
        }

        return 0;
    }

    static class Pos {
        private int l;
        private int r;
        private int c;

        public Pos(int l, int r, int c) {
            this.l = l;
            this.r = r;
            this.c = c;
        }

        public void setPos(int l, int r, int c) {
            this.l = l;
            this.r = r;
            this.c = c;
        }

        public boolean isEnd() {
            if (this.l == 0 && this.r == 0 && this.c == 0) {
                return true;
            }
            return false;
        }

        public int getL() {
            return l;
        }

        public int getR() {
            return r;
        }

        public int getC() {
            return c;
        }
    }
}