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
int N, M, k;
pair<int, int> smellBoard[21][21]; //번호, 시각
int dx[5] = {0,-1,1,0,0};//X위아왼오
int dy[5] = {0,0,0,-1,1};
int sharkD[401];
pair<int, int> sharkLoc[401];
vector<int> sharkPriority[401][5];
void sharkSmell(int now) {
    for (int i = 1; i <= M; i++)
        smellBoard[sharkLoc[i].first][sharkLoc[i].second] = { i,now };
}
void sharkMove(int now) {
    for (int i = 1; i <= M; i++) {
        int x = sharkLoc[i].first;
        int y = sharkLoc[i].second;
        int d = sharkD[i];
        if (x == -1) continue;
        bool noSmell = false;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[sharkPriority[i][d][j]];
            int ny = y + dy[sharkPriority[i][d][j]];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (now > (smellBoard[nx][ny].second + k)
                || smellBoard[nx][ny].second == -1) {
                sharkLoc[i].first = nx;
                sharkLoc[i].second = ny;
                sharkD[i] = sharkPriority[i][d][j];
                noSmell = true;
                break;
            }
        }
        if (!noSmell) {
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[sharkPriority[i][d][j]];
                int ny = y + dy[sharkPriority[i][d][j]];
                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (smellBoard[nx][ny].first == i) {
                    sharkLoc[i].first = nx;
                    sharkLoc[i].second = ny;
                    sharkD[i] = sharkPriority[i][d][j];
                    break;
                }
            }
        }
    }
}
void sharkDel() {
    for (int i = 1; i < M; i++) {
        if (sharkLoc[i].first == -1) continue;
        for (int j = i + 1; j <= M; j++) {
            if (sharkLoc[i].first == sharkLoc[j].first &&
                sharkLoc[i].second == sharkLoc[j].second)
                sharkLoc[j].first = -1;
        }
    }
}
bool one() {
    int cnt = 0;
    for (int i = 1; i <= M; i++) if (sharkLoc[i].first != -1) cnt++;
    if (cnt == 1) return true;
    return false;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            int num; cin >> num;
            if (num) sharkLoc[num] = { i,j };
        }
    for (int i = 1; i <= M; i++) cin >> sharkD[i];
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= 4; j++)
            for (int k = 1; k <= 4; k++) {
                int d; cin >> d;
                sharkPriority[i][j].push_back(d);
            }
    int ans = -1;
    memset(smellBoard, -1, sizeof(smellBoard));
    sharkSmell(0);
    for (int sec = 1; sec <= 1000; sec++) {
        sharkMove(sec);
        sharkDel();
        sharkSmell(sec);
        if (one()) {
            ans = sec;
            break;
        }
    }
    cout << ans;
    return 0;
}