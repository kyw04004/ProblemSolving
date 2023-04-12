import java.util.*;
class Solution {
    static Queue<Integer> priorityQueue = new PriorityQueue<>();
    public int solution(int[] scovilleList, int K) {
        int answer = 0;
        for(int scovile : scovilleList) {
            priorityQueue.add(scovile);
        }
        while(priorityQueue.size() >= 2 && priorityQueue.peek() < K) {
            answer++;
            priorityQueue.add(priorityQueue.remove() + priorityQueue.remove() * 2);
            if(priorityQueue.size() == 1) {
                if(priorityQueue.peek() >= K) return answer;
                else return -1;
            }
        }
        return answer;
    }
}