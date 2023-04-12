import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(String[] operations) {
        List<Integer> arrayList = new ArrayList<>();
        for(String operation : operations) {
            char op = operation.charAt(0);
            if(op == 'I') {
                int num = Integer.parseInt(operation.substring(2));
                arrayList.add(num);
            }
            else {
                if(arrayList.isEmpty()) continue;
                if(operation.charAt(2) == '1') {
                    arrayList.remove(arrayList.size() - 1);
                }
                else {
                    arrayList.remove(0);
                }
            }
            arrayList = arrayList.stream().sorted(Comparator.comparingInt(Integer::new)).collect(Collectors.toList());
        }
        if(arrayList.isEmpty()) return new int[]{0, 0};
        else return new int[]{arrayList.get(arrayList.size()-1),arrayList.get(0)};
    }
}