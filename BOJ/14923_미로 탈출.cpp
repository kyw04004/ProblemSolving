#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
int N, M, Hx, Hy, Ex, Ey, board[1001][1001], chk[2][1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    chk[0][Hx][Hy] = 1;
    q.push({ {Hx,Hy},{0,0} });
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int use = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();
        if (x == Ex && y == Ey) return dist;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (use == 0) {
                if (board[nx][ny] == 0 && !chk[0][nx][ny]) {
                    chk[0][nx][ny] = 1;
                    q.push({ {nx,ny}, {0, dist + 1} });
                }
                if (board[nx][ny] == 1 && !chk[1][nx][ny]) {
                    chk[1][nx][ny] = 1;
                    q.push({ {nx,ny}, {1, dist + 1} });
                }
            }
            if (use == 1) {
                if (board[nx][ny] == 0 && !chk[1][nx][ny]) {
                    chk[1][nx][ny] = 1;
                    q.push({ {nx,ny}, {1, dist + 1} });
                }
            }
        }
    }
    return -1;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    cout << bfs();
    return 0;
}
