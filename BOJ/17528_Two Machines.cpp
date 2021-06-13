//knapsack algorithm
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N, A[251], B[251], dp[251][62501][2];
int dfs(int index, int time, int AB) {
	if (index == N) return time;
	int &ret = dp[index][time][AB];
	if (ret != -1) return ret;
	ret = 1e9;
	if (AB == 0) { // A
		//A사용
		ret = min(ret, dfs(index + 1, time + A[index], 0));
		//B사용
		if (time > B[index]) ret = min(ret, dfs(index + 1, time - B[index], 0) + B[index]);
		else  ret = min(ret, dfs(index + 1, B[index] - time, 1) + time);
	}
	else { // B
		//B사용
		ret = min(ret, dfs(index + 1, time + B[index], 1));
		//A사용
		if (time > A[index]) ret = min(ret, dfs(index + 1, time - A[index], 1) + A[index]);
		else  ret = min(ret, dfs(index + 1, A[index] - time, 0) + time);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0);
	return 0;
}