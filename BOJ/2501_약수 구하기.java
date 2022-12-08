import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        List<Integer> divisors = Stream.iterate(1, n -> n <= N, n -> n + 1).filter(n -> N % n == 0).limit(K).collect(Collectors.toList());
        if(divisors.size() < K) System.out.println(0);
        else System.out.println(divisors.get(divisors.size()-1));
    }
}
