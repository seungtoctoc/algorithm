import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int d;
    static PriorityQueue<Info> infoPQ = new PriorityQueue<>(Comparator
            .comparingInt(Info::getStart)
            .thenComparingInt(Info::getEnd)
            .thenComparingInt(Info::getDistance));

    public static void main(String[] args){
        getInput();
        System.out.println(getMinDistance());
    }

    static void getInput() {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        d = scanner.nextInt();

        for (int i = 0 ; i < n ; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            int distance = scanner.nextInt();

            if (end - start > distance && end <= d) {
                infoPQ.add(new Info(start, end, distance));
            }
        }
    }

    static int getMinDistance() {
        int[] minDistance = new int[d + 1];

        for (int i = 1 ; i <= d ; i++) {
            minDistance[i] = i;
        }

        while(!infoPQ.isEmpty()) {
            Info info = infoPQ.poll();

            int start = info.getStart();
            int end = info.getEnd();
            int distance = info.getDistance();

            for(int i = 0 ; end + i <= d ; i++) {
                if (minDistance[end+i] < minDistance[start] + distance + i) {
                    break;
                }

                minDistance[end+i] = minDistance[start] + distance + i;
            }
        }

        return minDistance[d];
    }

    static class Info {
        int start;
        int end;
        int distance;

        public Info(int start, int end, int distance) {
            this.start = start;
            this.end = end;
            this.distance = distance;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }

        public int getDistance() {
            return distance;
        }
    }
}