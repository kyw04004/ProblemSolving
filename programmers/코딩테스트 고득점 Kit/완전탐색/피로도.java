import java.util.*;

class Solution {
    static int[] check;
    static int length;
    static List<List<Integer>> sequenceList = new ArrayList<>();
    public int solution(int k, int[][] dungeons) {
        int maxCount = 0;
        length = dungeons.length;
        check = new int[length];
        for(int i=0;i<length;i++) check[i] = 0;
        makeSequence(new ArrayList<>());
        for(List<Integer> sequence :  sequenceList) {
            int hp = k;
            int count = 0;
            for(int i=0;i<length;i++) {
                int canHp = dungeons[sequence.get(i)][0];
                int damage = dungeons[sequence.get(i)][1];
                if(hp >= canHp) {
                    hp -= damage;
                    count++;
                }
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
    
    private static void makeSequence(List<Integer> list) {
        if(list.size() == length) {
            sequenceList.add(new ArrayList<>(list));
            return;
        }
        for(int i=0;i<length;i++) {
            if(check[i] == 1) continue;
            check[i] = 1;
            list.add(i);
            makeSequence(list);
            list.remove(list.size()-1);
            check[i] = 0;
        }
    }
}