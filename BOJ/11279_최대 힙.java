import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static Queue<Integer> pq = new PriorityQueue<>(Comparator.comparing(Integer::intValue).reversed());
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        input();
        System.out.println(sb);
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++) {
            int num = Integer.parseInt(br.readLine());
            if(num == 0) {
                if(pq.isEmpty()) sb.append(0).append("\n");
                else sb.append(pq.poll()).append("\n");
            }
            else pq.add(num);
        }
    }
}