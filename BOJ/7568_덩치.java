import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        ArrayList<Person> personArrayList = new ArrayList<>();
        for(int i=0;i<N;i++) {
            StringTokenizer personInform = new StringTokenizer(br.readLine(), " ");
            int weight = Integer.parseInt(personInform.nextToken());
            int height = Integer.parseInt(personInform.nextToken());
            personArrayList.add(new Person(weight, height));
        }

        personArrayList.forEach((p) ->
            personArrayList.forEach((pp) -> {
                if(pp.getHeight() > p.getHeight() && pp.getWeight() > p.getWeight()) p.countRank();
            })
        );

        personArrayList.forEach(sb::append);
        System.out.println(sb);
    }
    public static class Person {
        int weight;
        int height;
        int rank = 1;
        Person(int weight, int height) {
            this.weight = weight;
            this.height = height;
        }

        public int getWeight() {
            return weight;
        }

        public int getHeight() {
            return height;
        }

        public void countRank() {
            this.rank++;
        }

        @Override
        public String toString() {
            return rank + " ";
        }
    }
}