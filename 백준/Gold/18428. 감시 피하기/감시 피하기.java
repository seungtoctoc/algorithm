import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static char[][] map;
    static ArrayList<Pos> teachers = new ArrayList<>();
    static String answer = "NO";

    public static void main(String[] args) throws IOException {
        getInput();
        setObstacle(0, 0, 0);
        System.out.println(answer);
    }

    static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        map = new char[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = st.nextToken().charAt(0);

                if (map[i][j] == 'T') {
                    teachers.add(new Pos(i, j));
                }
            }
        }
    }

    static void setObstacle(int x, int y, int cnt) {
        if (answer == "YES") {
            return;
        }

        if (cnt == 3) {
            if (check() == true) {
                answer = "YES";
            }

            return;
        }

        for (int i = y + 1 ; i < map.length ; i++) {
            if (map[x][i] == 'X') {
                map[x][i] = 'O';
                setObstacle(x, i, cnt + 1);
                map[x][i] = 'X';
            }
        }

        for (int i = x + 1 ; i < map.length ; i++) {
            for (int j = 0 ; j < map.length ; j++) {
                if (map[i][j] == 'X') {
                    map[i][j] = 'O';
                    setObstacle(x, i, cnt + 1);
                    map[i][j] = 'X';
                }
            }
        }
    }

    static boolean check() {
        for (int i = 0 ; i < teachers.size() ; i++) {
            int x = teachers.get(i).getX();
            int y = teachers.get(i).getY();

            for (int j = 0 ; j < 4 ; j++) {
                if (checkDir(x, y, j) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    static boolean checkDir(int x, int y, int dir) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        while (nx >= 0 && nx < map.length && ny >=0 && ny < map.length) {
            if (map[nx][ny] == 'S') {
                return false;
            }
            if (map[nx][ny] == 'O') {
                return true;
            }
            nx += dx[dir];
            ny += dy[dir];
        }

        return true;
    }

    static class Pos {
        int x;
        int y;

        public Pos (int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

}