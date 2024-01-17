import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static int[][] board = new int[9][9];

    public static void main(String[] args) {
        for (int i = 0 ; i < 9 ; i++) {
            String input = scanner.nextLine();
            String[] strArray = input.split("");

            for (int j = 0 ; j < 9 ; j++) {
                board[i][j] = Integer.parseInt(strArray[j]);
            }
        }

        DFS(0,0);
    }

    static boolean finish = false;
    static void DFS(int x, int y) {

        if (finish == true) {
            return;
        }

        if (board[x][y] > 0) {
            callNextDFS(x, y);
        }

        if (board[x][y] == 0) {
            ArrayList<Integer> possible = getInitArrayList();
            possible = checkColumn(x, y, possible);
            possible = checkRow(x, y, possible);
            possible = checkSquare(x, y, possible);

            if (possible.size() == 0) {
                return;
            }

            for (int i = 0 ; i < possible.size() ; i++) {
                board[x][y] = possible.get(i);
                callNextDFS(x, y);
            }
            board[x][y] = 0;
        }
    }

    static void callNextDFS(int x, int y) {
        if (y+1 < 9) {
            DFS(x, y+1);
            return;
        }

        if (x+1 < 9) {
            DFS(x+1, 0);
            return;
        }

        finish = true;
        printBoard();
    }

    static void printBoard() {
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }

    static ArrayList<Integer> getInitArrayList() {
        ArrayList<Integer> initArrayList = new ArrayList<>();

        for (int i = 1 ; i <= 9 ; i++) {
            initArrayList.add(i);
        }

        return initArrayList;
    }

    static ArrayList<Integer> checkRow(int x, int y, ArrayList<Integer> possible) {
        for (int i = 0 ; i < 9 ; i++) {
            possible.remove(Integer.valueOf(board[x][i]));
        }
        return possible;
    }

    static ArrayList<Integer> checkColumn(int x, int y, ArrayList<Integer> possible) {
        for (int i = 0 ; i < 9 ; i++) {
            possible.remove(Integer.valueOf(board[i][y]));
        }
        return possible;
    }

    static ArrayList<Integer> checkSquare(int x, int y, ArrayList<Integer> possible) {
        int pointX = x - x % 3;
        int pointY = y - y % 3;

        int[] dx = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        int[] dy = {0, 1, 2, 0, 1, 2, 0, 1, 2};

        for (int i = 0 ; i < 9 ; i++) {
            int checkPointX = pointX + dx[i];
            int checkPointY = pointY + dy[i];

            possible.remove(Integer.valueOf(board[checkPointX][checkPointY]));
        }

        return possible;
    }
}