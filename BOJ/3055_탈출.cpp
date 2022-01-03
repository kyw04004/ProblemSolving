#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int R, C, chk[2][51][51]; // 0 : È«¼ö, 1 : µµÄ¡
char board[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int,int>, pair<int, int>>> q;
int bfs() {
    while (!q.empty()) {
        int who = q.front().first.first;
        int cnt = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (who == 1 && board[x][y] == 'D') return cnt;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (chk[who][nx][ny] || board[nx][ny] == 'X' || board[nx][ny] == '*') continue;
            chk[who][nx][ny] = 1;
            if (who == 0) {
                if (board[nx][ny] == 'D') continue;
                else {
                    board[nx][ny] = '*';
                    q.push({ {who, cnt + 1},{nx,ny} });
                }
            }
            if (who == 1) q.push({ {who, cnt + 1},{nx,ny} });
        }
    }
    return -1;
}
int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> board[i][j];
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (board[i][j] == '*') {
                q.push({ {0, 0 }, {i,j} });
                chk[0][i][j] = 1;
            }
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (board[i][j] == 'S') {
                q.push({ {1,0}, {i,j} });
                chk[1][i][j] = 1;
            }
    int ans = bfs();
    if (ans == -1) cout << "KAKTUS";
    else cout << ans;
    return 0;
}