#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n, Map[16][16],dp[16][10][(1<<15)+1];
int go(int now, int val, int key) {
	int &ret = dp[now][val][key];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 1; i <= n; i++) {
		if (i == now) continue;
		int nkey = (key | (1 << (i - 1)));
		int nextval = Map[now][i];
		if (!(key & (1<<(i-1))) && val <= nextval)
			ret = max(ret, go(i, nextval, nkey)+1);
	}
	return ret;
}
int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			char val;
			cin >> val;
			Map[i][j] = val - '0';
		}
	cout << go(1,0,1) << "\n";
	return 0;
}