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
int N, K, state[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<int> v[101];
bool difK() {
    int Max = 0, Min = 1e9;
    for (int i = 1; i <= N; i++)
        for (int e : v[i])
            Max = max(Max, e), Min = min(Min, e);
    return (Max - Min) <= K ? true : false;
}
void addFish() {
    int Min = 1e9;
    for (int i = 1; i <= N; i++) 
        Min = min(Min, v[i][0]);
    for (int i = 1; i <= N; i++)
        if (Min == v[i][0]) v[i][0]++;
}
void rotate() {
    v[2].push_back(v[1][0]);
    v[1].pop_back();
    int last = 2;
    while (1) {
        stack<int> s;
        for (int i = last; i <= N; i++) {
            if (v[i].size() >= 2)
                s.push(i);
            else {
                last = i;
                break;
            }
        }
        if (s.empty()) break;
        else {
            int size = v[s.top()].size();
            if (size > (N - last + 1)) break;
            while (!s.empty()) {
                int idx = s.top();
                s.pop();
                for (int i = 0; i < size; i++)
                    v[last + i].push_back(v[idx][i]);
                v[idx].clear();
            }
            if (size == (N - last + 1)) break;
        }
    }
}
void fishMove() {
    memset(state, 0, sizeof(state));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || nx > N) continue;
                if (ny < 0 || ny >= v[nx].size()) continue;
                int dif = v[i][j] - v[nx][ny];
                if (dif >= 5) {
                    state[i][j] -= dif / 5;
                    state[nx][ny] += dif / 5;
                }
            }
        }
    }
    for(int i=1;i <= N;i++)
        for (int j = 0; j < v[i].size(); j++)
            v[i][j] += state[i][j];
}
void oneLineSort() {
    vector<int> newV[101];
    int idx = 1;
    for (int i = 1; i <= N; i++)
        for (int e : v[i])
            newV[idx++].push_back(e);
    for (int i = 1; i <= N; i++) v[i] = newV[i];
}
void rotate2() {
    for (int i = 1; i <= N/2 ;i++) {
        while (v[i].size()) {
            v[N - i + 1].push_back(v[i].back());
            v[i].pop_back();
        }
    }
    for (int i = 1; i <= N/4 ; i++) {
        while (v[N/2 + i].size()) {
            v[N - i + 1].push_back(v[N/2 + i].back());
            v[N/2 + i].pop_back();
        }
    }
}
void print() {
    for (int i = 1; i <= N; i++)
        cout << v[i][0] << ' ';
    cout << '\n';
}
void print2() {
    for (int i = 1; i <= N; i++) {
        for (int e : v[i])
            cout << e << ' ';
        cout << '\n';
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        v[i].push_back(num);
    }
    int step = 0;
    while (difK() == false) {
        step++;
        addFish();
        rotate();
        fishMove();
        oneLineSort();
        rotate2();
        fishMove();
        oneLineSort();
    }
    cout << step;
    return 0;
}