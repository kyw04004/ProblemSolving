#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, m, h[5001],dp[5001],Max;
vector<int> v[5001];
int go(int now, int depth) {
	int &ret = dp[now];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (h[next] > h[now])
			ret=max(ret, go(next, depth + 1)+1);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) go(i,1);
	for (int i = 1; i <= n; i++) printf("%d\n",dp[i]);
	return 0;
}