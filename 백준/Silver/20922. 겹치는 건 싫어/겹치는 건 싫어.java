import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int[] numbers;

    public static void main(String[] args) throws IOException {
        int k = getInput();
        System.out.println(getLength(k));
    }

    static int getInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        numbers = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0 ; i < n ; i++) {
            int num = Integer.parseInt(st.nextToken());
            numbers[i] = num;
        }

        return k;
    }

    static int getLength(int k) {
        int answer = 0;
        int left = 0;

        int[] cnt = new int[100_001];

        for (int right = 0 ; right < numbers.length ; right++) {
            cnt[numbers[right]]++;

            while (cnt[numbers[right]] > k) {
                cnt[numbers[left]]--;
                left++;

                if (numbers.length - left < answer) {
                    return answer;
                }
            }

            if (right - left + 1 > answer) {
                answer = right - left + 1;
            }
        }

        return answer;
    }
}