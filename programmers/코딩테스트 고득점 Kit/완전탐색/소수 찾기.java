import java.util.*;

class Solution {
    int cnt = 0;
    int[] chk = new int[10];
    HashMap <Integer, Integer> m = new HashMap<>();
    ArrayList<Integer> num = new ArrayList<>();
    public int solution(String numbers) {
         for(int i=0;i<numbers.length();i++) {
             int n = numbers.charAt(i) - '0';
             num.add(n);
         }
        go(0, numbers);
        return cnt;
    }
    
    public void go(int val, String numbers) {
        if(val > 0 && !m.containsKey(val)) {
            if(prime(val)) {
                cnt++;
                System.out.println(val);
            }
            m.put(val, 1);
        }
        for(int i=0;i<num.size();i++) {
            if(chk[i] == 0) {
                if(val == 0 && num.get(i) == 0) continue;
                chk[i] = 1;
                go(val * 10 + num.get(i), numbers);
                chk[i] = 0;
            }
        }
            
    }
    
    public boolean prime(int val) {
        boolean prime = true;
        if(val == 1) prime = false;
        for(int i=2;i<val;i++)
            if(val % i == 0) prime = false;
        return prime;
    }
    
}