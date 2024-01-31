import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int[] durability;
    static int n, k;

    public static void main(String[] args) throws IOException {
        getInput();
        System.out.println(simulating());
    }

    static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        durability = new int[2 * n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < 2 * n ; i++) {
            durability[i] = Integer.parseInt(st.nextToken());
        }
    }


    static int simulating() {
        int upPos = 0;
        int downPos = n - 1;
        int time = 1;

        Queue<Integer> robots = new LinkedList<>();

        while(true) {
            // 1
            upPos = getPreviousPos(upPos);
            downPos = getPreviousPos(downPos);

            if (!robots.isEmpty() && robots.peek() == downPos) {
                robots.poll();
            }


            // 2
            ArrayList<Integer> nextRobots = new ArrayList<>();
            while (!robots.isEmpty()) {
                int current = robots.poll();
                int nextPos = current;
                int nextPosCheck = getNextPos(current);

                if (durability[nextPosCheck] > 0 && (nextRobots.isEmpty() || nextRobots.get(nextRobots.size() - 1) != nextPosCheck)) {
                    durability[nextPosCheck]--;
                    nextPos = nextPosCheck;
                }

                if (nextPos != downPos) {
                    nextRobots.add(nextPos);
                }
            }
            robots = new ArrayDeque<>(nextRobots);


            // 3
            if (durability[upPos] > 0) {
                durability[upPos]--;
                robots.add(upPos);
            }

            // 4
            if (get0Durability() >= k) {
                return time;
            }

            time++;
        }
    }

    static int getNextPos(int pos) {
        if (pos == 2 * n - 1) {
            return 0;
        }
        return pos + 1;
    }

    static int getPreviousPos(int pos) {
        if (pos == 0) {
            return 2 * n - 1;
        }
        return pos - 1;
    }
    static int get0Durability() {
        int result = 0;

        for (int i = 0 ; i < durability.length ; i++) {
            if (durability[i] == 0) {
                result++;
            }
        }
        return result;
    }
}