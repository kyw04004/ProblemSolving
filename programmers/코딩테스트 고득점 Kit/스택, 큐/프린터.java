import java.util.*;
class Document {
    private int location;
    private int priority;
    Document(int location, int priority) {
        this.location = location;
        this.priority = priority;
    }
    public int getLocation() {
        return location;
    }
    public int getPriority() {
        return priority;
    }
}
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Integer> pQueue = new PriorityQueue<>(Comparator.reverseOrder());
        Queue<Document> queue = new LinkedList<>();
        for(int i=0;i<priorities.length;i++) pQueue.add(priorities[i]);
        for(int i=0;i<priorities.length;i++) queue.add(new Document(i, priorities[i]));
        int order = 1;
        while(!pQueue.isEmpty()) {
            if(queue.peek().getPriority() == pQueue.peek()) {
                if(queue.peek().getLocation() == location) {
                    answer = order;
                    break;
                }
                queue.remove();
                pQueue.remove();
                order++;
            }
            else {
                queue.add(queue.remove());
            }
        }
        return answer;
    }
}