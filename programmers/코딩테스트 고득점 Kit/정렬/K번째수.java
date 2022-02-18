import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i=0;i<commands.length;i++) {
            ArrayList<Integer> arr = new ArrayList<>();
            int s = commands[i][0];
            int e = commands[i][1];
            int rank = commands[i][2];
            for(int j= s - 1;j < e; j++) arr.add(array[j]);
            Collections.sort(arr);
            answer[i] = arr.get(rank-1);
        }
        return answer;
    }
}