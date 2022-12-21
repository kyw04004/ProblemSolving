import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int [][] array;

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(Arrays.stream(array).flatMapToInt(Arrays::stream).sorted().limit(N*N - N + 1).max().getAsInt());
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        array = new int[N][N];
        for(int i=0;i<N;i++) {
            StringTokenizer numsInput = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++)
                array[i][j] = Integer.parseInt(numsInput.nextToken());
        }

    }
}