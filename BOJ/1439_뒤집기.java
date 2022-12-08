import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int zeroLine = 0;
        int oneLine = 0;
        char beforeNumber = S.charAt(0);
        if(beforeNumber == '0') zeroLine++;
        else oneLine++;
        for(int i=1;i<S.length();i++) {
            char nowNumber = S.charAt(i);
            if(beforeNumber != nowNumber) {
                if (nowNumber == '1') oneLine++;
                else zeroLine++;
                beforeNumber = nowNumber;
            }
        }
        System.out.println(Math.min(zeroLine, oneLine));
    }
}
