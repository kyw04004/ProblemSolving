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
int board[12][12], paperCnt[5] = {5,5,5,5,5}, sum, Min = 1e9, chk[11][11];
bool canPaper(int s, int x, int y) {
    if (x + s > 10 || y + s > 10) return false;
    bool success = true;
    for(int i=x;i<=x+s;i++)
        for(int j=y;j<=y+s;j++)
            if (board[i][j] == 0 || chk[i][j] == 1) {
                success = false;
                break;
            }
    return success;
}
void chkPaper(int s, int x, int y) {
    bool success = true;
    for (int i = x; i <= x + s; i++)
        for (int j = y; j <= y + s; j++)
            chk[i][j] = 1;
}
void delPaper(int s, int x, int y) {
    bool success = true;
    for (int i = x; i <= x + s; i++)
        for (int j = y; j <= y + s; j++)
            chk[i][j] = 0;
}
void go(int x, int y, int paper, int cnt) {
    if (sum == cnt) {
        Min = min(Min, paper);
        return;
    }
    if (y > 10 || paper >= Min) return;
    if (board[x][y] == 0 || chk[x][y] == 1) {
        if (x == 10) go(1, y + 1, paper, cnt);
        else go(x + 1, y, paper, cnt);
    }
    else {
        for (int size = 0; size < 5; size++) {
            if (paperCnt[size] == 0) continue;
            if (canPaper(size, x, y)) {
                paperCnt[size] -= 1;
                chkPaper(size, x, y);
                if (x == 10) go(1, y + 1, paper + 1, cnt + pow(size + 1, 2));
                else go(x + 1, y, paper + 1, cnt + pow(size + 1, 2));
                paperCnt[size] += 1;
                delPaper(size, x, y);
            }
        }
    }
    return;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            cin >> board[i][j];
            sum += board[i][j];
        }
    go(1, 1, 0, 0);
    if (Min == 1e9) Min = -1;
    cout << Min;
    return 0;
}