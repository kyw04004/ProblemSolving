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
int Max, N, cnt=0;
vector<vector<int>> move(vector<vector<int>> args, int d) {
    if (d == 1) {//위
        for (int j = 0; j < N; j++) {
            vector<int> v;
            for (int i = 0; i < N; i++) //당기기
                if (args[i][j]) v.push_back(args[i][j]);
            for (int i = 0; i < v.size() - 1 && v.size() > 0; i++) { //합치기
                if (v[i] == -1) continue;
                if (v[i] == v[i + 1]) v[i] += v[i + 1], v[i + 1] = -1;
            }
            int idx = 0;
            for (int i = 0; i < N; i++) {//세팅
                if (idx < v.size()) {
                    if (v[idx] == -1) i--;
                    else args[i][j] = v[idx];
                    Max = max(Max, v[idx++]);
                }
                else args[i][j] = 0;
            }
        }
    }
    if (d == 2) {//아래
        for (int j = 0; j < N; j++) {
            vector<int> v;
            for (int i = N-1; i >= 0; i--) //당기기
                if (args[i][j]) v.push_back(args[i][j]);
            for (int i = 0; i < v.size() - 1 && v.size() > 0; i++) { //합치기
                if (v[i] == -1) continue;
                if (v[i] == v[i + 1]) v[i] += v[i + 1], v[i + 1] = -1;
            }
            int idx = 0;
            for (int i = N-1; i >= 0; i--) {//세팅
                if (idx < v.size()) {
                    if (v[idx] == -1) i++;
                    else args[i][j] = v[idx];
                    Max = max(Max, v[idx++]);
                }
                else args[i][j] = 0;
            }
        }
    }
    if (d == 3) {//좌
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = 0; j < N; j++) //당기기 
                if (args[i][j]) v.push_back(args[i][j]);
            for (int j = 0; j < v.size() - 1 && v.size() > 0; j++) { //합치기
                if (v[j] == -1) continue;
                if (v[j] == v[j + 1]) v[j] += v[j + 1], v[j + 1] = -1;
            }
            int idx = 0;
            for (int j = 0; j < N; j++) {//세팅
                if (idx < v.size()) {
                    if (v[idx] == -1) j--;
                    else args[i][j] = v[idx];
                    Max = max(Max, v[idx++]);
                }
                else args[i][j] = 0;
            }
        }
    }
    if (d == 4) {//우
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = N-1; j >= 0; j--) //당기기
                if (args[i][j]) v.push_back(args[i][j]);
            for (int j = 0; j < v.size() - 1 && v.size() > 0; j++) { //합치기
                if (v[j] == -1) continue;
                if (v[j] == v[j + 1]) v[j] += v[j + 1], v[j + 1] = -1;
            }
            int idx = 0;
            for (int j = N-1; j >= 0; j--) {//세팅
                if (idx < v.size()) {
                    if (v[idx] == -1) j++;
                    else args[i][j] = v[idx];
                    Max = max(Max, v[idx++]);
                }
                else args[i][j] = 0;
            }
        }
    }
    return args;
}
void go(int depth, vector<vector<int>> args) {
    if (depth == 5) {
        return;
    }
    for (int i = 1; i <= 4; i++)
        go(depth + 1, move(args, i));
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<vector<int>> board;
    cin >> N;
    board.resize(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int num; cin >> num;
            board[i].push_back(num);
            Max = max(Max, num);
        }
    go(0, board);
    cout << Max;
    return 0;
}