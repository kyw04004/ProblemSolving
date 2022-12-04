import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.util.Comparator.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> arrayList = new ArrayList<>();
        for(int i=0;i<N;i++) {
            arrayList.add(Integer.parseInt(br.readLine()));
        }
        arrayList.sort(comparing(Integer::intValue));
        double avg = arrayList.stream().mapToDouble(Integer::intValue).average().getAsDouble();
        int median = arrayList.get(N/2);
        int range = arrayList.get(N-1) - arrayList.get(0);
        Map<Integer, Integer> map = new HashMap<>();
        for (Integer i : arrayList) {
            if(map.containsKey(i)) map.replace(i, map.get(i) + 1);
            else map.put(i, 1);
        }

        int maxCount = 0;
        for (int key : map.keySet()) {
            int count = map.get(key);
            if (count > maxCount) {
                maxCount = count;
            }
        }

        ArrayList<Integer> modeList = new ArrayList<>();
        for (int key : map.keySet()) {
            int count = map.get(key);
            if (count == maxCount) modeList.add(key);
        }
        int mode = modeList.get(0);

        if(modeList.size() > 1) {
            modeList.sort(Integer::compareTo);
            mode = modeList.get(1);
        }

        System.out.println(Math.round(avg));
        System.out.println(median);
        System.out.println(mode);
        System.out.println(range);
    }
}