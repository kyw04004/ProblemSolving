import java.util.*;
class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        Map<String, Integer> rankKeyName = new HashMap<>();
        Map<Integer, String> rankKeyRank = new HashMap<>();
        for(int ranking=0;ranking< players.length;ranking++) {
            rankKeyName.put(players[ranking], ranking);
            rankKeyRank.put(ranking, players[ranking]);
        }
        for(int i=0;i< callings.length;i++) {
            int rank2 = rankKeyName.get(callings[i]);
            String rank1Name = rankKeyRank.get(rank2-1);
            
            rankKeyName.put(callings[i], rank2-1);
            rankKeyName.put(rank1Name, rank2);
            
            rankKeyRank.put(rank2-1, callings[i]);
            rankKeyRank.put(rank2, rank1Name);
        }
        for(int i=0;i< players.length;i++) answer[i] = rankKeyRank.get(i);
        return answer;
    }
}