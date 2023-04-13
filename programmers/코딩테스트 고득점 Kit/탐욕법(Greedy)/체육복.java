import java.util.*;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] clothes = new int[n];
        for(int i=0;i<n;i++) clothes[i] = 1;
        for(int i=0;i<lost.length;i++) clothes[lost[i]-1]--;
        for(int i=0;i<reserve.length;i++) clothes[reserve[i]-1]++;
        for(int i=0;i<n;i++) {
            if(clothes[i] > 0) {
                answer++;
            }
            if(i - 1 >= 0 && clothes[i-1] == 0 && clothes[i] == 2) {
                answer++;
                continue;
            }
            if(clothes[i] == 2 && i + 1 < n && clothes[i+1] == 0) {
                clothes[i+1]++;
            }
        }
        return answer;
    }
}