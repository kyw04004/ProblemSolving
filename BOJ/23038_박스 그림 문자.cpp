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
int N, M;
int dx[4] = { 0,0,-2,2 }; // LRUD
int dy[4] = { -2,2,0,0 };
char board[905][905];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < 3 * N; i++)
        for (int j = 0; j < 3 * M; j++)
            cin >> board[i][j];


    for (int i = 1; i < 3 * N; i += 3) {
        for (int j = 1; j < 3 * M; j += 3) {
            if (((i / 3) + (j / 3)) % 2 == 0) continue;
            int left = 0, right = 0, up = 0, down = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= 3 * N || ny < 0 || ny >= 3 * M) continue;
                if (board[nx][ny] == '#') {
                    if (k == 0) left = 1;
                    if (k == 1) right = 1;
                    if (k == 2) up = 1;
                    if (k == 3) down = 1;
                }
            }
            if (left + right + up + down) board[i][j] = '#';
            if (left) board[i][j - 1] = '#';
            if (right) board[i][j + 1] = '#';
            if (up) board[i - 1][j] = '#';
            if (down) board[i + 1][j] = '#';
        }
    }
    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < 3 * M; j++)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}