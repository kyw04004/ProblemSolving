import java.util.*;
class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int sum = 0;
        Arrays.sort(sequence);
        int start = 0, end = 0;
        int Min = 1000000;
        int idx = 0;
        while(end<sequence.length) {
            sum += sequence[end];
            while(sum > k && start < sequence.length) {
                sum -= sequence[start++];
            }
            if(sum == k && Min > (end-start)) {
                Min = end-start;
                answer[0] = start;
                answer[1] = end;
            }
            end++;
        }
        return answer;
    }
}