import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import static java.util.Comparator.comparing;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();
        for(int i=0;i<n;i++) {
            String str = br.readLine();
            if(set.contains(str)) continue;
            set.add(str);
            list.add(str);
        }
        list.sort(comparing(String::length).thenComparing(String::compareTo));
        list.forEach((num) -> sb.append(num).append("\n"));
        System.out.println(sb);
    }
}
