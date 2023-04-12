import java.util.*;
class Solution {
    static class Job_RequestFirst {
        public int requestTime;
        public int requiredTime;
        Job_RequestFirst(int one, int two) {
            requestTime = one;
            requiredTime = two;
        }
    }
    static class Job_RequiredFirst {
        public int requiredTime;
        public int requestTime;
        Job_RequiredFirst(int one, int two) {
            requiredTime = one;
            requestTime = two;
        }
    }
    static Queue<Job_RequestFirst> requestPQ = new PriorityQueue<>((Job_RequestFirst a, Job_RequestFirst b) -> {
        if(a.requestTime == b.requestTime) return a.requiredTime - b.requiredTime;
        return a.requestTime - b.requestTime;
    });
    static Queue<Job_RequiredFirst> requiredPQ = new PriorityQueue<>((Job_RequiredFirst a, Job_RequiredFirst b) -> {
        if(a.requiredTime == b.requiredTime) return a.requestTime - b.requestTime;
        return a.requiredTime - b.requiredTime;
    });
    public int solution(int[][] jobs) {
        int totalTime = 0;
        int now = 0;
        for (int[] job : jobs) requestPQ.add(new Job_RequestFirst(job[0], job[1]));
        while(!requestPQ.isEmpty() || !requiredPQ.isEmpty()) {
            while(!requestPQ.isEmpty() && now >= requestPQ.peek().requestTime) {
                Job_RequestFirst job = requestPQ.remove();
                requiredPQ.add(new Job_RequiredFirst(job.requiredTime, job.requestTime));
            }
            if(!requiredPQ.isEmpty()) {
                Job_RequiredFirst job = requiredPQ.remove();
                totalTime += (now - job.requestTime);
                totalTime += job.requiredTime;
                now += job.requiredTime;;
            }
            else now++;
        }
        return totalTime / jobs.length;
    }
}