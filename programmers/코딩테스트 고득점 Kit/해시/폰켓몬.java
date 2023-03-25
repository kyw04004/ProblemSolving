import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int typeCount = 0;
        int totalCount = nums.length;
        Map<Integer, Integer> typeMap = new HashMap<>();
        for(int num : nums) {
            if(!typeMap.containsKey(num)) {
                typeCount++;
                typeMap.put(num, 1);
            }
        }
        if(typeCount >= totalCount / 2) return totalCount / 2;
        return typeCount;
    }
}