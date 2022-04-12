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
int N, board[10][10], point;
void moveBlue(int t, int x, int y) {
    if (t <= 2) {
        int j;
        for (j = 0; j < 10; j++)
            if (board[x][j]) break;
        board[x][j - 1] = 1;
        if (t == 2) board[x][j - 2] = 1;
    }
    else {
        int j;
        for (j = 0; j < 10; j++)
            if (board[x][j] || board[x+1][j]) break;
        board[x][j - 1] = 1;
        board[x + 1][j - 1] = 1;
    }
}
void moveGreen(int t, int x, int y) {
    if (t % 2) {
        int i;
        for (i = 0; i < 10; i++)
            if (board[i][y]) break;
        board[i - 1][y] = 1;
        if (t == 3) board[i - 2][y] = 1;
    }
    else {
        int i;
        for (i = 0; i < 10; i++)
            if (board[i][y] || board[i][y+1]) break;
        board[i - 1][y] = 1;
        board[i - 1][y + 1] = 1;
    }
}
void strongBlueClear() { //열이 가득 차면 포인트
    for (int j = 9; j >= 4; j--) {
        bool full = true;
        for (int i = 0; i < 4; i++) 
            if (!board[i][j]) {
                full = false;
                break;
            }
        if (full) {
            point++;
            for (int i = 0; i < 4; i++) board[i][j] = 0;
            for (int x = 0; x < 4; x++)
                for (int y = j; y >= 5; y--) {
                    board[x][y] = board[x][y - 1];
                    board[x][y - 1] = 0;
                }
            j++;
        }
    }
}
void strogGreenClear() { // 행이가득 차면 포인트
    for (int i = 9; i >= 4; i--) {
        bool full = true;
        for (int j = 0; j < 4; j++)
            if (!board[i][j]) {
                full = false;
                break;
            }
        if (full) {
            point++;
            for (int j = 0; j < 4; j++) board[i][j] = 0;
            for (int x = i; x >= 5; x--)
                for (int y = 0; y < 4; y++) {
                    board[x][y] = board[x - 1][y];
                    board[x - 1][y] = 0;
                }
            i++;
        }
    }
}
void lightBlueClear() { // 열에 존재하면 포인트
    for (int t = 4; t < 6; t++) {
        bool exist = false;
        for (int i = 0; i < 4; i++)
            if (board[i][t]) {
                exist = true;
                break;
            }
        if (exist) {
            for (int i = 0; i < 4; i++) board[i][9] = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 9; j > t; j--) {
                    board[i][j] = board[i][j - 1];
                    board[i][j - 1] = 0;
                }
            for (int i = 0; i < 4; i++) board[i][t] = 0;
        }
    }
}
void lightGreenClear() { // 행에 존재하면 포인트
    for (int t = 4; t < 6; t++) {
        bool exist = false;
        for (int j = 0; j < 4; j++)
            if (board[t][j]) {
                exist = true;
                break;
            }
        if (exist) {
            for (int j = 0; j < 4; j++) board[9][j] = 0;
            for (int i = 9; i > t; i--)
                for (int j = 0; j < 4; j++) {
                    board[i][j] = board[i-1][j];
                    board[i - 1][j] = 0;
                }
            for (int j = 0; j < 4; j++) board[t][j] = 0;
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t, x, y; cin >> t >> x >> y;
        moveBlue(t, x, y);
        moveGreen(t, x, y);
        strongBlueClear();
        strogGreenClear();
        lightBlueClear();
        lightGreenClear();
    }
    cout << point <<'\n';
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 4; j < 10; j++)
            cnt += board[i][j];
    for (int i = 4; i < 10; i++)
        for (int j = 0; j < 4; j++)
            cnt += board[i][j];
    cout << cnt;
    return 0;
}