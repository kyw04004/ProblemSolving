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
int n, m, parent[1000005];
int find(int x) {
	if (parent[x] == x) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	else parent[y] = x;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int select, a, b;
		cin >> select >> a >> b;
		if (select == 1) {
			if (isUnion(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if(isUnion(a, b)) continue;
			else merge(a, b);
		}
	}
	return 0;
}