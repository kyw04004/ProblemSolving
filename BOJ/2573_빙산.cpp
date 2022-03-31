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
int N, M, iceberg[301][301], cnt = 1, year, chk[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void melt() {
    int zeroCnt[301][301] = {};
    for(int i=2;i<N;i++)
        for(int j=2;j<M;j++)
            for(int k=0;k < 4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!iceberg[nx][ny]) zeroCnt[i][j]++;
            }
    for (int i = 2; i < N; i++)
        for (int j = 2; j < M; j++)
            iceberg[i][j] = max(iceberg[i][j] - zeroCnt[i][j], 0);
}
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    chk[x][y] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!iceberg[nx][ny] || chk[nx][ny]) continue;
            chk[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}
int count() {
    int c = 0;
    memset(chk, 0, sizeof(chk));
    for(int i=2;i<N;i++)
        for(int j=2;j<M;j++)
            if (iceberg[i][j] && !chk[i][j]) {
                c++;
                bfs(i, j);
            }
    return c;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> iceberg[i][j];
    while (cnt == 1) {
        melt();
        cnt = count();
        if (cnt == 0) {
            year = 0;
            break;
        }
        year++;
    }
    cout << year;
    return 0;
}