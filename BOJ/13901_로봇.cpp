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
unordered_map<int, pair<int, int>> m;
int R, C, k, x,y;
int board[1001][1001], chk[1001][1001];
vector<int> dir;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    m[1] = { -1,0 }, m[2] = { 1,0 }, m[3] = { 0,-1 }, m[4] = { 0,1 };
    cin >> R >> C;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int br, bc; cin >> br >> bc;
        board[br][bc] = -1;
    }
    cin >> x >> y;
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int d; cin >> d;
        dir.push_back(d);
    }
    int d = 0;
    while (1) {
        bool go = false;
        for (int i = 0; i < 4; i++) {
            int nd = (d + i) % 4;
            int nx = x + m[dir[nd]].first;
            int ny = y + m[dir[nd]].second;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (chk[nx][ny] || board[nx][ny] == -1) continue;
            chk[nx][ny] = 1;
            d = nd;
            go = true, x = nx, y = ny;
            break;
        }
        if (!go) break;
    }
    cout << x << ' ' << y;
    return 0;
}
