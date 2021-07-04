#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int N, R, gigaN, gigaL, maxBranch, chk[200005], sum;
vector<pair<int, int>> v[200005];
void dfs1(int now, int dist) { // 기가 노드와 기둥 거리 구하기
	chk[now] = 1;
	if ((now == R && v[now].size() >= 2) ||
		(v[now].size() >= 3)) {
		gigaN = now;
		gigaL = dist;
		return;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int nextL = v[now][i].second;
		if (chk[next] == 0)
			dfs1(next, dist + nextL);
	}
}

void dfs2(int now, int dist) { // 제일 긴 가지 구하기
	chk[now] = 1;
	maxBranch = max(maxBranch, dist);
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int nextL = v[now][i].second;
		if (chk[next] == 0)
			dfs2(next, dist + nextL);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> R;
	for (int i = 0; i < N - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({ b,d });
		v[b].push_back({ a,d });
		sum += d;
	}
	dfs1(R, 0);
	if (gigaN == 0)
		cout << sum << ' ' << 0;
	else {
		dfs2(gigaN, 0);
		cout << gigaL << ' ' << maxBranch;
	}
	return 0;
}