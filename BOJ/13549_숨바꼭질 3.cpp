#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int N, K, dist[200005];
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
int bfs(int st) {
    dist[st] = 0;
    pq.push({ 0, st });
    while (!pq.empty()) {
        int now = pq.top().second;
        int time = pq.top().first;
        pq.pop();
        if (now == K) return time;
        if (now - 1 >= 0 && dist[now - 1] > time + 1) {
            dist[now - 1] = time + 1;
            pq.push({ time + 1, now - 1 });
        }
        if ((now + 1) <= 1e5 && dist[now + 1] > time + 1) {
            dist[now + 1] = time + 1;
            pq.push({ time + 1, now + 1 });
        }
        if ((2 * now) <= 2e5 && dist[2 * now] > time) {
            dist[2 * now] = time;
            pq.push({ time, 2 * now });
        }
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i <= 1e5; i++) dist[i] = 1e9;
    cout << bfs(N);
    return 0;
}