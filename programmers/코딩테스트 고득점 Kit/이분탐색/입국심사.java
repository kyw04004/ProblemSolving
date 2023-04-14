class Solution {
    public static final long MAX_TOTAL_TIME = 1000000000000000000L;
    public boolean canExamineTime(long examineTime, int[] times, int n) {
        long count = 0;
        for(int time : times) {
            count += examineTime / time;
        }
        if(count >= n) return true;
        else return false;
    }
    
    public long solution(int n, int[] times) {
        long answer = MAX_TOTAL_TIME;
        long left = 0, right = MAX_TOTAL_TIME;
        while(left <= right) {
            long mid = (left + right) / 2;
            if(canExamineTime(mid, times, n)) {
                right = mid - 1;
                answer = mid;
            }
            else left = mid + 1;
        }
        return answer;
    }
}