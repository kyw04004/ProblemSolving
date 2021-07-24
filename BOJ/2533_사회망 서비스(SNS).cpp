#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int N, ear[1000005], chk[1000005];
vector<int> v[1000005], tree[1000005];
void make_tree(int now) {
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!chk[next]) {
			tree[now].push_back(next);
			make_tree(next);
		}
	}
}
void make_ans(int now) {
	int cnt = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (tree[next].size() == 0) cnt++;
		else make_ans(next);
	}
	if (cnt == tree[now].size()) ear[now] = 1;
	cnt = 0;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (ear[next]) cnt++;
	}
	if (cnt != tree[now].size()) ear[now] = 1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	make_tree(1);
	make_ans(1);
	int ans = 0;
	for (int i = 1; i <= N; i++) if (ear[i]) ans++;
	cout << ans;
	return 0;
}