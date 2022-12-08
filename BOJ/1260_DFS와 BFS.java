import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer>[] arrayList;
    static boolean[] visited;
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int startVertex = Integer.parseInt(st.nextToken());
        arrayList = new ArrayList[N+1];
        for(int i=1;i<=N;i++) {
            arrayList[i] = new ArrayList<>();
        }
        for(int i=0;i<M;i++) {
            StringTokenizer edge = new StringTokenizer(br.readLine(), " ");
            int vertex1 = Integer.parseInt(edge.nextToken());
            int vertex2 = Integer.parseInt(edge.nextToken());
            arrayList[vertex1].add(vertex2);
            arrayList[vertex2].add(vertex1);
        }
        for(int i=1;i<=N;i++) {
            arrayList[i].sort(Integer::compareTo);
        }
        visited = new boolean[N+1];
        dfs(startVertex);
        sb.append("\n");
        visited = new boolean[N+1];
        bfs(startVertex);
        System.out.println(sb);
    }

    static void dfs(int now) {
        visited[now] = true;
        sb.append(now).append(" ");
        for(int next : arrayList[now]) {
            if(!visited[next]) {
                visited[next] = true;
                dfs(next);
            }
        }
    }

    static void bfs(int startVertex) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startVertex);
        visited[startVertex] = true;
        while(!queue.isEmpty()) {
            int now = queue.poll();
            sb.append(now).append(" ");
            for(int next : arrayList[now]) {
                if(!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }
    }
}
