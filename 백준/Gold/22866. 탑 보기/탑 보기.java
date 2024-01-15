import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static ArrayList<Integer> heights = new ArrayList<>();
    static int[] count = new int[100_001];
    static int[] nearBuilding = new int[100_001];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        heights.add(0);
        for (int i = 0 ; i < n ; i++) {
            int height = scanner.nextInt();
            heights.add(height);
        }

        leftToRight();
        rightToLeft();

        for (int i = 1 ; i <= n ; i++) {
            if (count[i] > 0) {
                System.out.println(count[i] + " " + nearBuilding[i]);
                continue;
            }
            System.out.println(count[i]);
        }
    }

    static class Building{
        int location;
        int height;

        public Building(int location, int height) {
            this.location = location;
            this.height = height;
        }

        public int getLocation() {
            return location;
        }

        public int getHeight() {
            return height;
        }
    }

    static void leftToRight() {
        Stack<Building> canSeeLeft = new Stack();

        for (int i = 1 ; i < heights.size() ; i++) {
            while (!canSeeLeft.empty()) {
                Building rearBuilding = canSeeLeft.peek();
                int rearHeight = rearBuilding.getHeight();

                if (rearHeight <= heights.get(i)) {
                    canSeeLeft.pop();
                    continue;
                }

                nearBuilding[i] = rearBuilding.getLocation();
                break;
            }

            count[i] = canSeeLeft.size();

            Building currentBuilding = new Building(i, heights.get(i));
            canSeeLeft.add(currentBuilding);
        }
    }

    static void rightToLeft() {
        Stack<Building> canSeeRight = new Stack();

        for (int i = heights.size() - 1 ; i > 0 ; i--) {
            while (!canSeeRight.empty()) {
                Building rearBuilding = canSeeRight.peek();
                int rearHeight = rearBuilding.getHeight();

                if (rearHeight <= heights.get(i)) {
                    canSeeRight.pop();
                    continue;
                }

                int nearLocation = rearBuilding.getLocation();
                if (nearBuilding[i] == 0 || i - nearBuilding[i] > nearLocation - i) {
                    nearBuilding[i] = nearLocation;
                }

                break;
            }

            count[i] += canSeeRight.size();

            Building currentBuilding = new Building(i, heights.get(i));
            canSeeRight.add(currentBuilding);
        }
    }
}