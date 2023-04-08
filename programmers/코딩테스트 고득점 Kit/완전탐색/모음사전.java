import java.util.*;
class Solution {
    static char[] alphabet = new char[]{'A','E','I','O','U'};
    static ArrayList<String> stringList = new ArrayList<>();
    public int solution(String word) {
        makeStringList("");
        for(int i=0;i<stringList.size();i++) {
            if(stringList.get(i).equals(word)) return i+1;
        }
        return -1;
    }
    public static void makeStringList(String str) {
        if(str.length() > 5) return;
        if(str.length() > 0) stringList.add(str);
        for(int i=0;i<5;i++) {
            makeStringList(str + alphabet[i]);
        }
    }
}