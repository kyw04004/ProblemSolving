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
int N, K, board[14][14], maxH;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> horse[13][13];
pair<int, int> pos[11];
void horseMove() {
    for (int i = 1; i <= K; i++) {
        int x = pos[i].first;
        int y = pos[i].second;
        int h;
        int d;
        for (int j = 0; j < horse[x][y].size(); j++) {
            if (horse[x][y][j].first == i) {
                h = j;
                d = horse[x][y][j].second;
                break;
            }
        }
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (board[nx][ny] == 2 || board[nx][ny] == -1) { // ÆÄ¶õ»ö
            if (d % 2) d -= 1;
            else d += 1;
            nx += 2 * dx[d];
            ny += 2 * dy[d];
            horse[x][y][h].second = d;
            if (board[nx][ny] == 2 || board[nx][ny] == -1) continue;
            else {
                i--;
                continue;
            }
        }
        else if (board[nx][ny] == 1) { // »¡°£»ö
            for (int j = horse[x][y].size() - 1; j >= h; j--) {
                horse[nx][ny].push_back({ horse[x][y][j] });
                pos[horse[x][y][j].first] = { nx,ny };
            }
            horse[x][y].erase(horse[x][y].begin() + h, horse[x][y].end());
            maxH = max(maxH, (int)horse[nx][ny].size());
            if (maxH >= 4) return;
        }
        else if (board[nx][ny] == 0) { //Èò»ö
            for (int j = h; j < horse[x][y].size(); j++) {
                horse[nx][ny].push_back({ horse[x][y][j] });
                pos[horse[x][y][j].first] = { nx,ny };
            }
            horse[x][y].erase(horse[x][y].begin() + h, horse[x][y].end());
            maxH = max(maxH, (int)horse[nx][ny].size());
            if (maxH >= 4) return;
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    memset(board, -1, sizeof(board));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    for (int i = 1; i <= K; i++) {
        int d, x, y; cin >> x >> y >> d;
        horse[x][y].push_back({ i,d - 1 });
        pos[i] = { x,y };
    }
    int turn;
    for (turn = 1; turn <= 1000; turn++) {
        horseMove();
        if (maxH >= 4) break;
    }
    if (turn == 1001) turn = -1;
    cout << turn;
    return 0;
}