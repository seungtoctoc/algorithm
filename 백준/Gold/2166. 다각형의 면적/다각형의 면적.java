import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        ArrayList<Pos> posList = new ArrayList<>();

        for (int i = 0 ; i < n ; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            Pos pos  = new Pos(x, y);
            posList.add(pos);
        }

        double result = 0;

        for (int i = 1 ; i < n - 1 ; i++) {
            Pos pos1 = posList.get(0);
            Pos pos2 = posList.get(i);
            Pos pos3 = posList.get(i+1);

            result += (double) CCW(pos1, pos2, pos3) * getArea(pos1, pos2, pos3);
        }

        result = Math.abs(result);
        DecimalFormat decimalFormat = new DecimalFormat("#.0");
        String roundedResult = decimalFormat.format(result);

        System.out.println(roundedResult);
    }

   static int CCW(Pos pos1, Pos pos2, Pos pos3) {
//        pos1 -> pos2 ->  pos3 의 방향 구하기
       long x1 = pos1.getX();
       long x2 = pos2.getX();
       long x3 = pos3.getX();

       long y1 = pos1.getY();
       long y2 = pos2.getY();
       long y3 = pos3.getY();

       long result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

       if (result > 0)
           return 1;
       if (result == 0)
           return 0;
       return -1;
   }

   static double getArea(Pos pos1, Pos pos2, Pos pos3) {
       double x1 = pos1.getX();
       double y1 = pos1.getY();
       double x2 = pos2.getX();
       double y2 = pos2.getY();
       double x3 = pos3.getX();
       double y3 = pos3.getY();

       double area = 0.5 * Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
       return area;
   }

   static class Pos {
        private int x;
        private int y;

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