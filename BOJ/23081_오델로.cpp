#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, Max, MaxX, MaxY;
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };
char board[505][505];

int makeCnt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        while (board[nx][ny] == 'W') {
            nx += dx[i];
            ny += dy[i];
            if (board[nx][ny] == '.' || nx < 0 || nx >= N || ny < 0 || ny >= N) break;
            if (board[nx][ny] == 'B') {
                while (1) {
                    nx -= dx[i];
                    ny -= dy[i];
                    if (nx == x && ny == y) break;
                    cnt++;
                }
                break;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    for (int i = 0; i < N; i++) // yÃà
        for (int j = 0; j < N; j++) { // xÃà
            if (board[i][j] != '.') continue;
            int cnt = makeCnt(i, j);
            if (cnt > Max) {
                Max = cnt;
                MaxX = j, MaxY = i;
            }
        }
    if (Max == 0) cout << "PASS";
    else cout << MaxX << ' ' << MaxY << '\n' << Max;
    return 0;
}