class Solution {
    boolean solution(String s) {
        int openCount = 0;
        
        for(char c : s.toCharArray()) {
            if(c == '(') openCount++;
            if(c == ')') openCount--;
            if(openCount < 0) return false;
        }

        return openCount == 0;
    }
}