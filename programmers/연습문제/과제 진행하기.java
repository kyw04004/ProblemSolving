import java.util.*;
import java.util.stream.Collectors;
class Solution {
    static private class Task {
        public int startTime;
        public int playTime;
        public String name;
        Task(String name, int startTime,int playTime) {
            this.name = name;
            this.startTime = startTime;
            this.playTime = playTime;
        }
    }
    
    public String[] solution(String[][] plans) {
        Queue<Task> waitQueue = new PriorityQueue<>(Comparator.comparingInt(a -> a.startTime));
        Stack<Task> keepStack = new Stack<>();
        String[] answer = new String[plans.length];
        int answerIdx = 0;
        for(String[] plan : plans) waitQueue.add(new Task(plan[0], Integer.parseInt(plan[1].substring(0,2)) * 60 + Integer.parseInt(plan[1].substring(3)), Integer.parseInt(plan[2])));
        Task doingTask = null;
        for(int time=0;time<=101540;time++) {
            if(!waitQueue.isEmpty() && time == waitQueue.peek().startTime) {
                if(doingTask != null) keepStack.add(doingTask);
                doingTask = waitQueue.remove();
            }
            if(doingTask != null) {
                doingTask.playTime--;
                if(doingTask.playTime == 0) {
                    answer[answerIdx++] = doingTask.name;
                    doingTask = null;
                    if(!keepStack.isEmpty()) doingTask = keepStack.pop();
                }
            }
        }
        return answer;
    }
}