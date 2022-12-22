import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static Stack<Integer> stack = new Stack<>();
    public static void main(String[] args) throws IOException {
        input();
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++) {
            StringTokenizer inputLine = new StringTokenizer(br.readLine(), " ");
            String command = inputLine.nextToken();
            if(command.equals("push")) {
                int num = Integer.parseInt(inputLine.nextToken());
                stack.push(num);
            }
            else if(command.equals("pop")) {
                if(stack.empty()) System.out.println(-1);
                else System.out.println(stack.pop());
            }
            else if(command.equals("size")) {
                System.out.println(stack.size());
            }
            else if(command.equals("empty")) {
                System.out.println(stack.empty()?1:0);
            }
            else if(command.equals("top")) {
                if(stack.empty()) System.out.println(-1);
                else System.out.println(stack.peek());
            }
        }
    }
}