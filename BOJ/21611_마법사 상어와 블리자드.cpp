#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, M, board[50][50], sum;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int px[4] = {0,1,0,-1};
int py[4] = {-1,0,1,0};
vector<int> valueStore() {
    vector<int> nums;
    int size = 1;
    int cnt = 0;
    int d = 0;
    int sX = (N + 1) / 2, sY = (N + 1) / 2;
    while (sX * sY != 1) {
        for (int s = 1; s <= size; s++) {
            sX += px[d];
            sY += py[d];
            if (board[sX][sY])
                nums.push_back(board[sX][sY]);
        }
        if (sX == 1 && sY == N) size--;
        cnt += 1; cnt %= 2;
        if (!cnt) size++;
        d += 1; d %= 4;
    }
    return nums;
}
void valueInput(vector<int> nums) {
    int size = 1;
    int cnt = 0;
    int d = 0;
    int sX = (N + 1) / 2, sY = (N + 1) / 2;
    int idx = 0;
    while (sX * sY != 1) {
        for (int s = 1; s <= size; s++) {
            sX += px[d];
            sY += py[d];
            if (idx < nums.size())
                board[sX][sY] = nums[idx++];
            else board[sX][sY] = 0;
        }
        if (sX == 1 && sY == N) size--;
        cnt += 1;
        if (cnt % 2 == 0) size++;
        d += 1; d %= 4;
    }
}
void magic(int d, int s) {
    int sX = (N + 1) / 2, sY = (N + 1) / 2;
    int cnt = 0;
    while (cnt < s) {
        cnt++;
        sX += dx[d - 1];
        sY += dy[d - 1];
        if (sX <1 || sX > N || sY < 1 || sY>N) continue;
        board[sX][sY] = 0;
    }
}
void pull() {
    vector<int> nums = valueStore();
    valueInput(nums);
}
bool bomb() {
    vector<int> nums = valueStore();
    bool success = false;
    for (int i = 0; i < nums.size(); i++) {
        int now = nums[i];
        int same = 0;
        for (int j = i + 1; j < nums.size(); j++) {
            if (now == nums[j]) same++;
            else break;
        }
        if (same >= 3) {
            success = true;
            for (int j = i; j <= i + same; j++)
                nums[j] = 0, sum+=now;
            i += same;
        }
    }
    valueInput(nums);
    return success;
}
void divide() {
    vector<int> nums = valueStore();
    vector<int> newNums;
    for (int i = 0; i < nums.size();) {
        int now = nums[i];
        int same = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (now == nums[j]) same++;
            else break;
        }
        newNums.push_back(same);
        newNums.push_back(now);
        i += same;
    }
    valueInput(newNums);
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    for (int i = 0; i < M; i++) {
        int d, s; cin >> d >> s;
        magic(d,s);
        pull();
        while (bomb())
            pull();
        divide();
    }
    cout << sum;
    return 0;
}