import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static Pos startPos;
    static Pos limitPos;
    static int[][] map;
    static int[][] vis;

    public static void main(String[] args) throws IOException {
        getMap();

        BFS();

        printVis();
    }

    static void getMap() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        limitPos = new Pos(n, m);

        map = new int[n][m];
        for (int i = 0 ; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0 ; j < m ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if (map[i][j] == 2) {
                    startPos = new Pos(i, j);
                }
            }
        }
    }

    static void BFS() {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        vis = new int[limitPos.getX()][limitPos.getY()];

        Queue<Pos> queue = new LinkedList<>();
        queue.add(startPos);

        while(!queue.isEmpty()) {
            Pos currentPos = queue.poll();

            int cx = currentPos.getX();
            int cy = currentPos.getY();

            for (int i = 0 ; i < 4 ; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                Pos nextPos = new Pos(nx, ny);

                if (canGo(nextPos, limitPos) == true && map[nx][ny] == 1 && vis[nx][ny] == 0) {
                    vis[nx][ny] = vis[cx][cy] + 1;
                    queue.add(nextPos);
                }
            }
        }
    }

    static boolean canGo(Pos now, Pos limit) {
        int x = now.getX();
        int y = now.getY();

        int lx = limit.getX();
        int ly = limit.getY();

        if (x < 0 || x >= lx) {
            return false;
        }

        if (y < 0 || y >= ly) {
            return false;
        }

        return true;
    }

    static void printVis() {
        StringBuilder sb = new StringBuilder();

        for (int i = 0 ; i < limitPos.getX() ; i++) {
            for (int j = 0 ; j < limitPos.getY() ; j++) {
                if (map[i][j] == 1 && vis[i][j] == 0) {
                    sb.append("-1 ");
                    continue;
                }

                sb.append(vis[i][j] + " ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    static class Pos {
        int x;
        int y;

        public Pos(int x, int y) {
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