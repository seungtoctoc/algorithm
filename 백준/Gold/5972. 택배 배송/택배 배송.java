import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws IOException {
        ArrayList<ArrayList<Road>> roads = getInput();
        int answer = simulate(roads);
        System.out.println(answer);
    }

    static ArrayList<ArrayList<Road>> getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Road>> roads = new ArrayList<>();

        for (int i = 0 ; i <= n ; i++) {
            roads.add(new ArrayList<>());
        }

        for (int i = 0 ; i < m ; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            roads.get(a).add(new Road(b, c));
            roads.get(b).add(new Road(a, c));
        }

        return roads;
    }

    static int simulate(ArrayList<ArrayList<Road>> roads) {
        PriorityQueue<Road> status = new PriorityQueue<>(Comparator.comparingInt(Road::getCost));
        status.add(new Road(1, 0));
        int answer = -1;
        int[] vis = new int[roads.size()];
        vis[1] = 1;

        while(!status.isEmpty()) {
            Road current = status.poll();
            int currentFarm = current.getFarm();
            int currentCost = current.getCost();

            vis[currentFarm] = 1;

            if (currentFarm == roads.size() - 1) {
                answer = currentCost;
                break;
            }

            for (int i = 0 ; i < roads.get(currentFarm).size() ; i++) {
                Road nextRoad = roads.get(currentFarm).get(i);
                if (vis[nextRoad.getFarm()] == 0) {
                    status.add(new Road(nextRoad.getFarm(), currentCost + nextRoad.cost));
                }
            }
        }

        return answer;
    }

    static class Road {
        int farm;
        int cost;

        public Road(int farm, int cost) {
            this.farm = farm;
            this.cost = cost;
        }

        public int getFarm() {
            return farm;
        }

        public int getCost() {
            return cost;
        }
    }
}