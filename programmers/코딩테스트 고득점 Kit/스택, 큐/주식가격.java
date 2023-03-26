import java.util.*;
class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        int Min = 100000;
        int last = 100000;
        Stack<Integer> seconds = new Stack<>();
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<prices.length;i++) stack.add(prices[i]);
        int idx = 0;
        while(!stack.empty()) {
            if(stack.peek() <= Min) {
                seconds.add(idx);
                Min = stack.peek();
            }
            else {
                if(stack.peek() > last) seconds.add(1);
                else {
                    int s = prices.length - 1 - idx;
                    int val = prices.length - 1 - s;
                    for(int i = s + 1;i < prices.length;i++) {
                        if(stack.peek() > prices[i]) {
                            val =  i - s;
                            break;
                        }
                    }
                    seconds.add(val);
                }
            }
            last = stack.pop();
            idx++;
        }
        for(int i=0;i<prices.length;i++) answer[i] = seconds.pop();
        return answer;
    }
}