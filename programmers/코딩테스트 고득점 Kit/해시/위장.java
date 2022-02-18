import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> m = new HashMap<>();
        for(int i=0;i<clothes.length;i++) {
            String type = clothes[i][1];
            if(m.containsKey(type)) m.put(type, m.get(type) + 1);
            else  m.put(type, 1);
        }
        for(int i=0;i < clothes.length;i++) {
            String type = clothes[i][1];
            if(m.get(type) != 0) {
                answer *= m.get(type) + 1;
                m.put(type, 0);
            }
        }
        return answer - 1;
    }
}