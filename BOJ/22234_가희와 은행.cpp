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
using namespace std;
typedef pair<int, pair<int, int>> e;
queue<e> q;
priority_queue<e, vector<e>, greater<e>> pq;
int N, T, W, M;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> T >> W;
	for (int i = 0; i < N; i++) {
		int p, t; cin >> p >> t;
		q.push({ 0, {p,t} });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int p, t, c; cin >> p >> t >> c;
		pq.push({ c,{p,t} });
	}
	for (int i = 0; i < W; ) {
		int now = q.front().first;
		int id = q.front().second.first;
		int time = q.front().second.second;
		q.pop();
		for (int j = 0; 0 < time && j < T && i < W; j++) {
			cout << id << '\n';
			time--, i++, now++;
		}
		while (!pq.empty() && i >= pq.top().first) {
			q.push(pq.top());
			pq.pop();
		}
		if (time > 0) q.push({ now, { id, time } });
	}
	return 0;
}