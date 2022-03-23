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
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int>> e;
int N, chk[4][51][51];
int dx[4] = { 0,0,-1,1 }; //¿À¿ÞÀ§¾Æ
int dy[4] = { 1,-1,0,0 };
char home[51][51];
pair<int, int> door;
int bfs() {
    priority_queue<e, vector<e>, greater<e>> pq;
    for (int i = 0; i < 4; i++) {
        chk[i][door.first][door.second] = 1;
        pq.push({ {0,i}, door });
    }
    while (!pq.empty()) {
        int cnt = pq.top().first.first;
        int d = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        if (!(door.first == x && door.second == y) && home[x][y] == '#') return cnt;
        pq.pop();
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (home[nx][ny] == '*') continue;
        if (chk[d][nx][ny]) continue;
        chk[d][nx][ny] = 1;
        pq.push({ {cnt,d}, {nx,ny} });
        if (home[nx][ny] == '!') {
            if (d % 2) d = (d + 1) % 4;
            else d = (d + 2) % 4;
            for (int i = d; i <= d + 1; i++) {
                if (chk[i][nx][ny]) continue;
                chk[i][nx][ny] = 1;
                pq.push({ {cnt + 1,i}, {nx,ny} });
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> home[i][j];
            if (home[i][j] == '#') door = { i,j };
        }
    cout << bfs();
    return 0;
}