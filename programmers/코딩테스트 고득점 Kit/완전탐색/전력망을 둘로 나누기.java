import java.util.*;
class Solution {
    static int[] check = new int[101];
    static int noWireIdx;
    static int count;
    public int solution(int n, int[][] wires) {
        int answer = 100;
        for (int i = 0; i < wires.length; i++) {
            noWireIdx = i;
            for (int j = 1; j <= n; j++) check[j] = 0;
            ArrayList<Integer> countList = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                count = 0;
                if (check[j] == 0) dfs(j, wires);
                if (count > 0) countList.add(count);
            }
            answer = Math.min(answer, Math.abs(countList.get(0) - countList.get(1)));
        }
        return answer;
    }
    public static void dfs(int now, int[][] wires) {
        count++;
        check[now] = 1;
        for (int i = 0; i < wires.length; i++) {
            int[] wire = wires[i];
            int start = wire[0];
            int finish = wire[1];
            if (start != now && finish != now) continue;
            if (i == noWireIdx) continue;
            if (start == now && check[finish] == 0) dfs(finish, wires);
            if (finish == now && check[start] == 0) dfs(start, wires);
        }
    }
}