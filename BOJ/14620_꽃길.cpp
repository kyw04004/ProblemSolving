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
int N, board[11][11], Min = 3000, chk[11][11], sum;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool can(int x, int y) {
    if (chk[x][y]) return false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > N) return false;
        else if (chk[nx][ny]) return false;
    }
    return true;
}
void check(int x, int y) {
    chk[x][y] = 1;
    sum += board[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        chk[nx][ny] = 1;
        sum += board[nx][ny];
    }
}
void uncheck(int x, int y) {
    chk[x][y] = 0;
    sum -= board[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        chk[nx][ny] = 0;
        sum -= board[nx][ny];
    }
}
void go(int depth, int x, int y) {
    if (sum > Min) return;
    if (depth == 3) {
        Min = min(Min, sum);
        return;
    }
    if (y > N) x += 1, y = 1;
    if (x > N) return;
    if (can(x, y)) {
        check(x, y);
        go(depth + 1, x, y + 1);
        uncheck(x, y);
    }
    go(depth, x, y + 1);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    go(0, 1, 1);
    cout << Min;
    return 0;
}
