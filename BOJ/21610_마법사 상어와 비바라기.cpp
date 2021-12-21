#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, M, board[51][51];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
queue<pair<int, int>> beforeC, afterC;
queue<pair<pair<int, int>, int>> copyW;
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    beforeC.push({ N-1,0 });
    beforeC.push({ N-1,1 });
    beforeC.push({ N - 2,0 });
    beforeC.push({ N - 2,1 });
    for (int i = 0; i < M; i++) {
        int chk[51][51] = {};
        int d, s; cin >> d >> s;
        while (!beforeC.empty()) {
            int x = beforeC.front().first;
            int y = beforeC.front().second;
            beforeC.pop();
            x += (dx[d - 1] * s);
            y += (dy[d - 1] * s);
            x += (50 * N);
            y += (50 * N);
            x %= N;
            y %= N;
            chk[x][y] = 1;
            board[x][y] += 1;
            afterC.push({ x,y });
        }
        while (!afterC.empty()) {
            int x = afterC.front().first;
            int y = afterC.front().second;
            afterC.pop();
            int cnt = 0;
            for (int j = 1; j <= 7; j += 2) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (board[nx][ny]) cnt++;
            }
            copyW.push({ {x,y}, cnt });
        }
        while (!copyW.empty()) {
            int x = copyW.front().first.first;
            int y = copyW.front().first.second;
            int cnt = copyW.front().second;
            copyW.pop();
            board[x][y] += cnt;
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (chk[x][y]) continue;
                if (board[x][y] >= 2) {
                    board[x][y] -= 2;
                    beforeC.push({ x,y });
                }
            }
        }
    }
    int sum = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sum += board[x][y];
    cout << sum;
    return 0;
}