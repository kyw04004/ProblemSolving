import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer inputNums = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(inputNums.nextToken());
        int M = Integer.parseInt(inputNums.nextToken());
        Map<String, Integer> mapNameToInt = new HashMap<>();
        String[] mapIntToName = new String[N+1];
        for(int i=1;i<=N;i++) {
            String name = br.readLine();
            mapNameToInt.put(name, i);
            mapIntToName[i] = name;
        }
        for(int i=0;i<M;i++) {
            String input = br.readLine();
            if('1' <= input.charAt(0) && input.charAt(0) <= '9') {
                int num = Integer.parseInt(input);
                sb.append(mapIntToName[num]).append('\n');
            }
            else {
                sb.append(mapNameToInt.get(input)).append('\n');
            }
        }
        System.out.println(sb);
     }
}
