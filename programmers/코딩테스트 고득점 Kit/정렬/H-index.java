import java.util.Arrays;
class Solution {
    public int solution(int[] citations) {
        int n = citations.length;
        int hIndex = 0;
        Arrays.sort(citations);
        for(int h=0;h<=1000;h++) {
            for(int i=0;i<citations.length;i++) {
                int num = citations[i];
                if(num >= h && citations.length - i >= h) {
                    hIndex = h;
                    break;
                }
            }
        }
        return hIndex;
    }
}