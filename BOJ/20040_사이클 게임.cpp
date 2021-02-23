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
int n, m, ans, parent[500005];
int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}
bool isUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return true;
	return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (!ans && isUnion(a + 1, b + 1)) ans = i;
		else merge(a + 1, b + 1);
	}
	cout << ans;
	return 0;
}