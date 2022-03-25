#include<iostream>
#include<map>
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
vector<pair<int, int>> chkPoint;
vector<pair<pair<int, int>, int>> heater;
int R, C, K, W, room[21][21], wall[2][21][21], choco, chk[21][21], del[21][21];
//¿À¿ÞÀ§¾Æ
int dx[4][3] = { {0,-1,1 },{0,-1,1},{-1,-1,-1},{1,1,1} };
int dy[4][3] = { {1,1,1},{-1,-1,-1},{0,-1,1},{0,-1,1} };
void input() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            int num; cin >> num;
            if (num == 0) continue;
            else if (num == 5) chkPoint.push_back({ i,j });
            else heater.push_back({ {i,j}, num - 1 });
        }
    cin >> W;
    for (int i = 0; i < W; i++) {
        int x, y, t; cin >> x >> y >> t;
        wall[t][x][y] = 1;
    }
}
void blow() {
    for (int i = 0; i < heater.size(); i++) {
        memset(chk, 0, sizeof(chk));
        int d = heater[i].second;
        queue<pair<pair<int, int>, int>> q;
        int x = heater[i].first.first + dx[d][0];
        int y = heater[i].first.second + dy[d][0];
        q.push({ {x, y}, 5 });
        chk[x][y] = 1;
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int h = q.front().second;
            q.pop();
            if (h == 0) continue;
            room[x][y] += h;
            for (int j = 0; j < 3; j++) {
                int nx = x + dx[d][j];
                int ny = y + dy[d][j];
                if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
                if (chk[nx][ny]) continue;
                int left = wall[1][x][y-1];
                int right = wall[1][x][y];
                int top = wall[0][x][y];
                int bottom = wall[0][x+1][y];
                //º®
                if (d == 0) {
                    if(wall[1][nx][ny - 1]) continue;
                    if (j == 1 && top) continue;
                    if (j == 2 && bottom) continue;
                }
                if (d == 1) {
                    if(wall[1][nx][ny]) continue;
                    if (j == 1 && top) continue;
                    if (j == 2 && bottom) continue;
                }
                if (d == 2) {
                    if (wall[0][nx + 1][ny]) continue;
                    if (j == 1 && left) continue;
                    if (j == 2 && right) continue;
                }
                if (d == 3) {
                    if (wall[0][nx][ny]) continue;
                    if (j == 1  && left) continue;
                    if (j == 2  && right) continue;
                }
                chk[nx][ny] = 1;
                q.push({ {nx,ny}, h - 1 });
            }
        }
    }
}
void control() {
    int sum[21][21] = {};
    for(int i=1;i<=R;i++)
        for (int j = 1; j <= C; j++) {
            int now = room[i][j];
            int minus = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d][0];
                int ny = j + dy[d][0];
                if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
                if (now <= room[nx][ny]) continue;
                if (d == 0 && wall[1][i][j]) continue;
                if (d == 1 && wall[1][nx][ny]) continue;
                if (d == 2 && wall[0][i][j]) continue;
                if (d == 3 && wall[0][nx][ny]) continue;
                minus -= (now - room[nx][ny]) / 4;
                sum[nx][ny] += (now - room[nx][ny]) / 4;
            }
            sum[i][j] += minus;
        }
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            room[i][j] += sum[i][j];
}
void delOutside() {
    for (int i = 1; i <= R; i++) {
        if (room[i][1] > 0) room[i][1]--;
        if (room[i][C] > 0) room[i][C]--;
    }
    for (int i = 2; i < C; i++) {
        if (room[1][i] > 0) room[1][i]--;
        if (room[R][i] > 0) room[R][i]--;
    }
}
bool investigate() {
    bool pass = true;
    for(int i=0;i<chkPoint.size();i++)
        if (room[chkPoint[i].first][chkPoint[i].second] < K) {
            pass = false;
            break;
        }
    return pass;
}
int main() {
    input();
    while (choco <= 100) {
        blow();
        control();
        delOutside();
        choco++;
        if(investigate()) break;
    }
    cout << choco;
    return 0;
}