import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer inputNAndX = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(inputNAndX.nextToken());
        int X = Integer.parseInt(inputNAndX.nextToken());
        StringTokenizer inputArray = new StringTokenizer(br.readLine(), " ");
        ArrayList<Integer> numList = new ArrayList<>();
        while(inputArray.hasMoreTokens()) {
            numList.add(Integer.parseInt(inputArray.nextToken()));
        }
        numList.stream().filter((num)-> num < X).forEach((num)->sb.append(num).append(" "));
        System.out.println(sb);
    }
}