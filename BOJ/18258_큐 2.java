import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static Deque<Integer> queue = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        input();
        System.out.println(sb);
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++) {
            StringTokenizer inputLine = new StringTokenizer(br.readLine(), " ");
            String command = inputLine.nextToken();
            if(command.equals("push")) {
                int num = Integer.parseInt(inputLine.nextToken());
                queue.add(num);
            }
            else if(command.equals("pop")) {
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.poll()).append("\n");
            }
            else if(command.equals("size")) {
                sb.append(queue.size()).append("\n");
            }
            else if(command.equals("empty")) {
                sb.append(queue.isEmpty()?1:0).append("\n");
            }
            else if(command.equals("front")) {
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.getFirst()).append("\n");
            }
            else if(command.equals("back")) {
                if(queue.isEmpty()) sb.append(-1).append("\n");
                else sb.append(queue.getLast()).append("\n");
            }
        }
    }
}