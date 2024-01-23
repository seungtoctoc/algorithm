import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
   public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

       StringTokenizer st = new StringTokenizer(br.readLine());
       int n = Integer.parseInt(st.nextToken());
       int k = Integer.parseInt(st.nextToken());

       Map<String, Integer> words = new HashMap();
       for (int i = 0 ; i < n ; i++) {
           String word = br.readLine();

           if (word.length() >= k) {
               words.put(word, words.getOrDefault(word, 0) + 1);
           }
       }

       Comparator<Word> comparator = Comparator
               .comparing(Word::getCnt, Comparator.reverseOrder())
               .thenComparing(Word::getLength, Comparator.reverseOrder())
               .thenComparing(Word::getWord);
       PriorityQueue<Word> pq = new PriorityQueue<>(comparator);

       words.forEach((word, cnt) -> {
           Word currentWord = new Word(word, cnt);
           pq.add(currentWord);
       });

       while (!pq.isEmpty()) {
           Word topWord = pq.poll();
           sb.append(topWord.getWord() + "\n");
       }

       System.out.println(sb);
    }

    static class Word {
       String word;
       int cnt;

       public Word(String word, int cnt) {
           this.word = word;
           this.cnt = cnt;
       }

        public String getWord() {
            return word;
        }

        public int getCnt() {
            return cnt;
        }

        public int getLength() {
           return word.length();
        }
    }
}