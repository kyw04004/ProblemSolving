#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int N, dp[505][505], mat[505][2];
int dfs(int st, int en) {
	if (st == en) return 0;
	int &ret = dp[st][en];
	if (ret != -1) return ret;
	ret = INT32_MAX;
	for (int i = st; i < en; i++)
		ret = min(ret, dfs(st,i) + dfs(i + 1, en) + mat[st][0] * mat[i+1][0] * mat[en][1]);
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> mat[i][0] >> mat[i][1];
	cout << dfs(0, N-1);
	return 0;
}