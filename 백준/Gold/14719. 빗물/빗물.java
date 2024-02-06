import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static ArrayList<Integer> blocks = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        getInput();
        int answer = getRainwater(0, blocks.size() - 1);
        System.out.println(answer);
    }

    static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < w; i++) {
            int block = Integer.parseInt(st.nextToken());
            blocks.add(block);
        }
    }

    static int getRainwater(int left, int right) {
        if (right - left <= 1) {
            return 0;
        }

        int[] result = getMaxTwoBlockIndex(left, right);
        int leftWall = result[0];
        int rightWall = result[1];

        return getRainwater(left, leftWall) + calculateBowl(leftWall, rightWall) + getRainwater(rightWall, right);
    }

    static int[] getMaxTwoBlockIndex(int left, int right) {
        PriorityQueue<Block> pq = new PriorityQueue<>(Comparator.comparingInt(Block::getHeight).reversed());
        for (int i = left ; i <= right ; i++) {
            Block block = new Block(i, blocks.get(i));
            pq.add(block);
        }

        int index1 = pq.poll().getIndex();
        int index2 = pq.poll().getIndex();

        int[] result = new int[2];
        result[0] = Math.min(index1, index2);
        result[1] = Math.max(index1, index2);

        return result;
    }

    static int calculateBowl(int left, int right) {
        int limit = Math.min(blocks.get(left), blocks.get(right));
        int result = 0;

        for (int i = left + 1 ; i < right ; i++) {
            result += limit - blocks.get(i);
        }

        return result;
    }


    static class Block {
        int index;
        int height;

        public Block(int index, int height) {
            this.index = index;
            this.height = height;
        }

        public int getIndex() {
            return index;
        }

        public int getHeight() {
            return height;
        }
    }
}