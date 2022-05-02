#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<string>> global_places;
bool bfs(int num, int x, int y) {
    int chk[6][6] = {};
    queue<pair<pair<int, int>, int>> q;
    q.push({ {x,y},0 });
    chk[x][y] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if (d > 1) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
            if (chk[nx][ny] || global_places[num][nx][ny] == 'X') continue;
            if (global_places[num][nx][ny] == 'P') return false;
            chk[nx][ny] = 1;
            q.push({ {nx,ny}, d + 1 });
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    global_places = places;
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        bool success = true;
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                if (places[i][x][y] == 'P') {
                    success = bfs(i, x, y);
                    if (success == false) x = 6, y = 6;
                }
        if (success) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}