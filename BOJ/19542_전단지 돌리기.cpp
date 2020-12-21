#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
queue<int> q;
vector<int> v[100001];
int n, s, d, chk[100001], sum, Dep[100001];
void depdfs(int now) {
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!chk[next]) {
			depdfs(next);
			Dep[now] = max(Dep[now], Dep[next] + 1);
		}
	}
}
void bfs(int now) {
	chk[now] = 1;
	q.push(now);
	while (!q.empty()) {
		int here = q.front();
		sum += 2;
		q.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i];
			if (!chk[next] && Dep[next] >= d) {
				chk[next] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> n >> s >> d;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	depdfs(s);
	memset(chk, 0, sizeof(chk));
	bfs(s);
	cout << sum-2;
	return 0;
}