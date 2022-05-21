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
int K, W, H, board[201][201], chk[31][201][201];
int hx[8] = {-1,-2,-2,-1,1,2,2,1};
int hy[8] = {-2,-1,1,2,-2,-1,1,2};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {0, 0 }, {1,1} }); //¿òÁ÷ÀÎÈ½¼ö, ¸» È½¼ö, À§Ä¡
    chk[0][1][1] = 1;
    while (!q.empty()) {
        int total = q.front().first.first;
        int horse = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == H && y == W) return total;
        if (horse < K)
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
                if (chk[horse + 1][nx][ny] || board[nx][ny]) continue;
                chk[horse + 1][nx][ny] = 1;
                q.push({ {total + 1, horse + 1},{nx,ny} });
            }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
            if (chk[horse][nx][ny] || board[nx][ny]) continue;
            chk[horse][nx][ny] = 1;
            q.push({ {total + 1, horse},{nx,ny} });
        }
    }
    return -1;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> K >> W >> H;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> board[i][j];
    cout << bfs();
    return 0;
}
