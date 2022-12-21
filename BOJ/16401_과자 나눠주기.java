import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static int[] array;

    public static void main(String[] args) throws IOException {
        input();
        int ans = binarySearch();
        System.out.println(ans);
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer MN = new StringTokenizer(br.readLine(), " ");
        M = Integer.parseInt(MN.nextToken());
        N = Integer.parseInt(MN.nextToken());
        array = new int[N];
        StringTokenizer ArrayInput = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) array[i] = Integer.parseInt(ArrayInput.nextToken());
        Arrays.sort(array);
    }
    public static int binarySearch() {
        int left = 1, right = 1000000000;
        int mid;
        int ans = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (can(mid)) {
                left = mid + 1;
                ans = mid;
            } else right = mid - 1;
        }
        return ans;
    }
    public static boolean can(int len) {
        long count = 0;
        for (int i = 0; i < N; i++)
            count += array[i] / len;
        return count >= M;
    }
}