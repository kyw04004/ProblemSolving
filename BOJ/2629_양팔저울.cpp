#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N, M, dp[35][110005],sum,marble;
vector<int> weights;
int dfs(int index, int weight) {
	if (weight == 55000 + marble) return 1;
	if (index == weights.size()) return 0;
	int &ret = dp[index][weight];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, dfs(index + 1, weight - weights[index]));
	ret = max(ret, dfs(index + 1, weight + weights[index]));
	ret = max(ret, dfs(index + 1, weight));
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int W; cin >> W;
		weights.push_back(W);
		sum += W;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> marble;
		if (dfs(0, 55000)) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}