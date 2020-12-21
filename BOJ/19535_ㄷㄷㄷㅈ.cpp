#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<stack>
using namespace std;
typedef long long ll;
pair <int, int> P;
pair<pair <int, int>, pair <int, int>> PP;
queue<pair<pair<int, int>, pair<int, int>>> q;
vector <ll> v[300001];
ll n, chk[300001], dcnt, gcnt;
void dfs(ll now, ll depth) {
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		ll next = v[now][i];
		if (!chk[next]) {
			dcnt += (v[now].size() - 1)*(v[next].size() - 1);
			dfs(next, depth + 1);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		ll len = v[i].size();
		if (len >= 3) 
			gcnt += ((len)*(len - 1)*(len - 2)) / 6;
	}
	if (dcnt == (3 * gcnt)) cout << "DUDUDUNGA";
	else if (dcnt > (3 * gcnt)) cout << "D";
	else cout << "G";
	return 0;
}