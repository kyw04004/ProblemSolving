import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int count;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        input();
        System.out.println(sb);
    }
    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++) {
            count = 0;
            String str = br.readLine();
            sb.append(isPalindrome(str.toCharArray(),0,str.length()-1)).append(" ").append(count).append("\n");
        }
    }
    public static int isPalindrome(char[] str, int l, int r) {
        count++;
        if(l>=r) return 1;
        else if(str[l] != str[r]) return 0;
        else return isPalindrome(str, l+1,r-1);
    }
}