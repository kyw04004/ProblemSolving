import java.util.;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashMapString, Integer m = new HashMap();
        for(String num  phone_book)
            m.put(num, 1);
        for(String num  phone_book)
            for(int i = 0; i  < num.length() - 1; i++) {
                String com = num.substring(0,i+1);
                if(m.containsKey(com)) answer = false;
            }
        return answer;
    }
}