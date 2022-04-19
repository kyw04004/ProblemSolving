#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
int N, M, board[21][21], chk[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int xMin, yMin, total, rainbow, point;
typedef struct {
    int total;
    int rainbow;
    int x;
    int y;
}blockGroup;
vector<blockGroup> v;
bool compare (blockGroup A, blockGroup B) {
    if (A.total != B.total) return A.total > B.total;
    else if (A.rainbow != B.rainbow) return A.rainbow > B.rainbow;
    else if (A.x != B.x) return A.x > B.x;
    else if (A.y != B.y) return A.y > B.y;
}
void bfs(int x, int y) {
    total = 0;
    rainbow = 0;
    int color = board[x][y];
    queue<pair<int, int>> q;
    q.push({ x,y });
    chk[x][y] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        total++;
        if (board[x][y] == 0) rainbow++;
        if (board[x][y] == color) {
            if (x < xMin) xMin = x, yMin = y;
            else if (x == xMin && y < yMin) yMin = y;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (chk[nx][ny] || (!(board[nx][ny] == color || board[nx][ny] == 0))) continue; 
            chk[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}
void choiceOne() {
    v.clear();
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (board[i][j] > 0) {
                memset(chk, 0, sizeof(chk));
                xMin = 1e9, yMin = 1e9;
                bfs(i, j);
                if (total > 1) v.push_back({ total,rainbow, xMin, yMin });
            }
    sort(v.begin(), v.end(), compare);
}
void deleteOne() {
    memset(chk, 0, sizeof(chk));
    int x = v[0].x;
    int y = v[0].y;
    point += v[0].total * v[0].total;
    bfs(x, y);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (chk[i][j]) board[i][j] = -1e9;
}
void gravity() {
    for (int y = 1; y <= N; y++)
        for (int x = N - 1; x >= 1; x--)
            if (board[x][y] > -1) {
                int nx;
                for (nx = x + 1; nx <= N; nx++)
                    if (board[nx][y] >= -1) break;
                if (x + 1 == nx) continue;
                board[nx - 1][y] = board[x][y];
                board[x][y] = -1e9;
            }
}
void ccw() {
    vector<int> v;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            v.push_back(board[i][j]);
    for (int j = 1; j <= N; j++)
        for (int i = N; i >= 1; i--)
            board[i][j] = v[cnt++];
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    while (1) {
        choiceOne();
        if (v.size() < 1) break;
        deleteOne();
        gravity();
        ccw();
        gravity();
    }
    cout << point;
    return 0;
}