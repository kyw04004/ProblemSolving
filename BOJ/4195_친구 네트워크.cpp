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
int t, n, parent[200005], friends[200005];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	else {
		parent[y] = x;
		friends[x] += friends[y];
		friends[y] = friends[x];
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		memset(parent, 0, sizeof(parent));
		int cnt = 0;
		map<string, int> m;
		cin >> n;
		for (int i = 1; i <= 2*n; i++) friends[i] = 1;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (m[a] == 0) {
				m[a] = ++cnt;
				parent[cnt] = cnt;
			}
			if (m[b] == 0) {
				m[b] = ++cnt;
				parent[cnt] = cnt;
			}
			merge(m[a], m[b]);
			int anc = find(m[a]);
			cout << friends[anc] << '\n';
		}
	}
	return 0;
}