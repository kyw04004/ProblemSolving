import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static Set<Integer> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        input();
        set.stream().sorted().forEach((num) -> System.out.print(num + " "));
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer numsInput = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) set.add(Integer.parseInt(numsInput.nextToken()));
    }
}