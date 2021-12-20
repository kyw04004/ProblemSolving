#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int n, dist[51][51];
char board[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
typedef pair<int, pair<int, int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
int bfs() {
    dist[1][1] = 0;
    pq.push({ 0, {1,1} });
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int bomb = pq.top().first;
        if (x == n && y == n) return bomb;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (board[nx][ny] == '1') {
                if (dist[nx][ny] > bomb) {
                    dist[nx][ny] = bomb;
                    pq.push({ bomb, {nx,ny} });
                }
            }
            else {
                if (dist[nx][ny] > (bomb + 1)) {
                    dist[nx][ny] = (bomb + 1);
                    pq.push({ bomb + 1, {nx,ny} });
                }
            }
       }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 1e9;
            cin >> board[i][j];
        }
    cout << bfs();
    return 0;
}