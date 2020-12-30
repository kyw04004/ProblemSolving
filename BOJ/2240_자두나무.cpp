#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int T, W, arr[1001], dp[1001][31][3];
int go(int depth, int w, int here) {
	if (depth >= T) return 0;
	int &ret = dp[depth][w][here];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[depth] == here) {
		ret = max(ret, go(depth + 1, w, here) + 1);
		if (w >= 1) ret = max(ret, go(depth + 1, w - 1, !here));
	}
	if (arr[depth] != here) {
		ret = max(ret, go(depth + 1, w, here));
		if (w >= 1) ret = max(ret, go(depth + 1, w - 1, !here) + 1);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T >> W;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
		arr[i] -= 1;
	}
	cout << go(0, W, 0) << '\n';
	return 0;
}