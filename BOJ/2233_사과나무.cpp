#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, X, Y, node = 0, a, b, len = -1;
string str;
vector<int> v[2005], ans[2005];
int depth[2005], parent[2005][12];
void dfs(int now, int dep) {
	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!depth[next]) {
			parent[next][0] = now;
			dfs(next, dep + 1);
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = 11; i >= 0; i--)
		if (depth[a] <= depth[parent[b][i]])
			b = parent[b][i];
	if (a == b) return a;
	for (int i = 11; i >= 0; i--)
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	return parent[a][0];
}
void make_tree(int now) {
	while (len+1 < str.size()) {
		len+=1;
		if (str[len] == '0') {
			v[now].push_back(++node);
			ans[node].push_back(len + 1);
			if (len + 1 == X) a = node;
			if (len + 1 == Y) b = node;
			make_tree(node);
		}
		else {
			ans[now].push_back(len + 1);
			if (len + 1 == X) a = now;
			if (len + 1 == Y) b = now;
			return;
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> str >> X >> Y;
	make_tree(0);
	dfs(1, 1);
	for (int j = 1; j <= 11; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	int now = LCA(a, b);
	for (int i = 0; i < ans[now].size(); i++)
		cout << ans[now][i] << ' ';
	return 0;
}