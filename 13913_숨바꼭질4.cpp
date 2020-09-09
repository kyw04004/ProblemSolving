#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
queue<pair<pair<int,int>,int>> q;
stack <int> s;
int n, m, chk[100001], trace[100001];
int bfs(int now) {
	chk[now] = 1;
	q.push({ {-1,now},0} );
	while (!q.empty()) {
		int before = q.front().first.first;
		int now = q.front().first.second;
		int cnt = q.front().second;
		trace[now] = before;
		q.pop();
		if (now == m) return cnt;
		int next1 = now * 2;
		int next2 = now + 1;
		int next3 = now - 1;
		if (next1 >= 0 && next1 <= 100000 && chk[next1] == 0)
		{
			chk[next1] = 1;
			q.push({ {now,next1}, cnt + 1 });
		}
		if (next2 >= 0 && next2 <= 100000 && chk[next2] == 0) {
			chk[next2] = 1;
			q.push({ {now, next2}, cnt + 1 });
		}
		if (next3 >= 0 && next3 <= 100000 && chk[next3] == 0) {
			chk[next3] = 1;
			q.push({ {now,next3}, cnt + 1 });
		}
	}
}
int main() {
	cin >> n >> m;
	int ans = bfs(n);
	int t = ans;
	s.push(m);
	while (trace[m] != -1) {
		s.push(trace[m]);
		m = trace[m];
	}
	printf("%d\n", ans);
	while (!s.empty()) {
		printf("%d ",s.top());
		s.pop();
	}
	return 0;
}