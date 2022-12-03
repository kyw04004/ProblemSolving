import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.util.Comparator.comparing;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<Pointer> list = new ArrayList<>();
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list.add(new Pointer(x,y));
        }
        list.sort(comparing(Pointer::getX).thenComparing(Pointer::getY));
        list.forEach(sb::append);
        System.out.println(sb);
    }

    public static class Pointer {
        int x;
        int y;
        Pointer(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }

        @Override
        public String toString() {
            return getX() + " " + getY() + "\n";
        }
    }
}
