#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
vector<int> v[100001];
int n, k, apart[100001], ind[100001], chk[100001], ans;
queue <int> q;
int main() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		ind[a]++;
		ind[b]++;
	}
	ans = n;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		apart[a] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (ind[i] == 1) {
			chk[i] = 1;
			q.push(i);
		}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (!apart[node]) {
			ans--;
			for (int i = 0; i < v[node].size(); i++) {
				int next = v[node][i];
				if (chk[next]) continue;
				ind[next]--;
				if (ind[next] == 1) {
					chk[next] = 1;
					q.push(next);
				}
			}
		}
	}
	cout << ans;
	return 0;
}