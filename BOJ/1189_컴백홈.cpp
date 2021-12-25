#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int R, C, K, chk[6][6], ans;
char board[6][6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int d) {
    if (d == K) {
        if (x == 1 && y == C) ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
        if (chk[nx][ny] || board[nx][ny] == 'T') continue;
        chk[nx][ny] = 1;
        dfs(nx, ny, d + 1);
        chk[nx][ny] = 0;
    }
}
int main() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> board[i][j];
    chk[R][1] = 1;
    dfs(R, 1, 1);
    cout << ans;
    return 0;
}