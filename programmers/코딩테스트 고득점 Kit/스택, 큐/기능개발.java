import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int chk[] = new int[100];
        int afterDays = 0;
        for(int i=0;i<progresses.length;i++) {
            for(int day=1;day<100;day++) {
                if(progresses[i] + day * speeds[i] >= 100) {
                    afterDays = Math.max(afterDays, day);
                    chk[afterDays]++;
                    break;
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for(int i=1;i<100;i++) if(chk[i] > 0) list.add(chk[i]);
        int[] answer = new int[list.size()];
        for(int i=0;i<answer.length;i++) answer[i] = list.get(i);
        return answer;
    }
}