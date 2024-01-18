import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
       int stick = 0;
       int result = 0;

       String input = scanner.nextLine();

       for (int i = 0 ; i < input.length() ; i++) {
           if (input.charAt(i) == '(') {
               stick++;
               result++;
               continue;
           }

           if (input.charAt(i - 1) == '(') {
               stick--;
               result--;
               result += stick;
               continue;
           }

           stick--;
       }

       System.out.println(result);
    }
}