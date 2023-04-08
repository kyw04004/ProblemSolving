class Solution {
    public int[] solution(int brown, int yellow) {
        int total = brown + yellow;
        for(int i=1; i <= (int) Math.sqrt(total); i++) {
            if(total % i != 0) continue;
            int width = total / i;
            int height = i;
            if(width * 2 + (height - 2) * 2 == brown) return new int[]{width, height};
        }
        return null;
    }
}