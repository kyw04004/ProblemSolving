#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int N, M, K, parent[10005], friendCost[10005], Min[10005], chk[10005], ans;
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
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> friendCost[i];
		parent[i] = i;
		Min[i] = 1e9;
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		if (!isUnion(a, b)) merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		int p = find(i);
		if (chk[p] == 0) chk[p] = 1;
		Min[p] = min(friendCost[i], Min[p]);
	}
	for (int i = 1; i <= N; i++)
		if (chk[i] == 1) ans += Min[i];
	if (ans <= K) cout << ans;
	else cout << "Oh no";
	return 0;
}