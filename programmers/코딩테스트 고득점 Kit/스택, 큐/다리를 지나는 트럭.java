import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int sum = 0;
        int nowBridgeWeight = 0;
        int EndWeight = 0;
        Queue<Integer> bridgeState = new LinkedList<>();
        Queue<Integer> truck = new LinkedList<>();
        for(int i=0;i<bridge_length;i++) bridgeState.add(0);
        for(int i=0;i<truck_weights.length;i++) truck.add(truck_weights[i]);
        for(int i=0;i<truck_weights.length;i++) sum += truck_weights[i];
        int second = 0;
        while(EndWeight < sum) {
            second++;
            nowBridgeWeight -= bridgeState.peek();
            EndWeight += bridgeState.remove();
            if(!truck.isEmpty() && nowBridgeWeight + truck.peek() <= weight) {
                bridgeState.add(truck.peek());
                nowBridgeWeight += truck.remove();
            }
            else bridgeState.add(0);
        }
        return second;
    }
}