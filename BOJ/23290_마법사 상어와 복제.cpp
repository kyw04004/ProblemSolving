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
vector<int> fish[5][5];
vector<int> duplicationInf[5][5];
int M, S, sx,sy, eatMax, ddd;
int fishSmell[5][5], chk[5][5];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int ddx[5] = { -100,-1,0,1,0 };
int ddy[5] = { -100,0,-1,0,1 };
void duplicateMagic() {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            duplicationInf[i][j] = fish[i][j]; 
        }
}
void fishMove(int turn) {
    vector<int> fishGone[5][5];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int fs = 0; fs < fish[i][j].size(); fs++) {
                int d = fish[i][j][fs];
                bool can = false;
                int nx;
                int ny;
                for(int t=0;t<8;t++) {
                    if (t > 0) d = (d + 7) % 8;
                    nx = i + dx[d];
                    ny = j + dy[d];
                    if (nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
                    if (turn < fishSmell[nx][ny] + 3) continue;
                    if (sx == nx && sy == ny) continue;
                    can = true;
                    break;
                }
                if (can) fishGone[nx][ny].push_back(d);
                else fishGone[i][j].push_back(fish[i][j][fs]);
            }
        }
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            fish[i][j] = fishGone[i][j];
}
void sharkGoing(int x, int y, int fishCnt, int dSum) {
    if (dSum >= 100) {
        if (fishCnt > eatMax) eatMax = fishCnt, ddd = dSum;
        else if (fishCnt == eatMax) ddd = min(ddd, dSum);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        int nx = x + ddx[i];
        int ny = y + ddy[i];
        if (nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
        if(chk[nx][ny]) sharkGoing(nx, ny, fishCnt, dSum * 10 + i);           
        else {
            chk[nx][ny] = 1;
            sharkGoing(nx, ny, fishCnt + fish[nx][ny].size(), dSum * 10 + i);
            chk[nx][ny] = 0;
        }
    }
}
void sharkMove(int turn) {
    eatMax = -1;
    ddd = 1e9;
    sharkGoing(sx,sy,0,0);
    for(int i=2;i>=0;i--) {
        int size = pow(10, i);
        sx += ddx[ddd / size];
        sy += ddy[ddd / size];
        if (fish[sx][sy].size() > 0) {
            fishSmell[sx][sy] = turn;
            fish[sx][sy].clear();
        }
        ddd %= size;
    }
}
void duplicate() {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            for (int d : duplicationInf[i][j])
                fish[i][j].push_back(d);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> S;
    memset(fishSmell, -1, sizeof(fishSmell));
    for (int i = 0; i < M; i++) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        fish[fx][fy].push_back(d-1);
    }
    cin >> sx >> sy;
    for (int i = 2; i <= S + 1; i++) {
        duplicateMagic();
        fishMove(i);
        sharkMove(i);
        duplicate();
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans += fish[i][j].size();
    cout << ans;
    return 0;
}