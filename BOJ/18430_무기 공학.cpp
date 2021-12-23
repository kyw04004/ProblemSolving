#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, M, board[7][7], Max, chk[7][7];
int dx[4] = { 0,0,-1,1 };//오른 왼 위 아래
int dy[4] = { 1,-1,0,0 };
int checkIn(int x, int y, int num1, int num2) {
    int sum = 0;
    sum += (2 * board[x][y]);
    sum += board[x + dx[num1]][y + dy[num1]];
    sum += board[x + dx[num2]][y + dy[num2]];
    chk[x][y] = 1;
    chk[x + dx[num1]][y + dy[num1]] = 1;
    chk[x + dx[num2]][y + dy[num2]] = 1;
    return sum;
}
int checkOut(int x, int y, int num1, int num2) {
    int sum = 0;
    sum -= (2 * board[x][y]);
    sum -= board[x + dx[num1]][y + dy[num1]];
    sum -= board[x + dx[num2]][y + dy[num2]];
    chk[x][y] = 0;
    chk[x + dx[num1]][y + dy[num1]] = 0;
    chk[x + dx[num2]][y + dy[num2]] = 0;
    return sum;
}
void go(int x, int y, int sum) {
    Max = max(Max, sum);
    if (y > M) x += 1, y = 1;
    if (x > N) return;
    if (chk[x][y]) {
        go(x, y + 1, sum);
        return;
    }
    int can[4] = {};
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (chk[nx][ny] || nx<1 || nx>N || ny<1 || ny>M) continue;
        can[k] = 1;
    }
    if (can[1] && can[3]) {
        sum += checkIn(x, y, 1, 3);
        go(x, y + 1, sum);
        sum += checkOut(x, y, 1, 3);
    }
    if (can[1] && can[2]) {
        sum += checkIn(x, y, 1, 2);
        go(x, y + 1, sum);
        sum += checkOut(x, y, 1, 2);
    }
    if (can[0] && can[3]) {
        sum += checkIn(x, y, 0, 3);
        go(x, y + 1, sum);
        sum += checkOut(x, y, 0, 3);
    }
    if (can[0] && can[2]) {
        sum += checkIn(x, y, 0, 2);
        go(x, y + 1, sum);
        sum += checkOut(x, y, 0, 2);
    }
    go(x, y + 1, sum);
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    if (N < 2 || M < 2) {
        cout << 0;
        return 0;
    }
    go(1, 1, 0);
    cout << Max;
    return 0;
}