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
int dp[505][505], file[505], sum[505];
int Sum(int S, int E) {
	if (S == E) return 0;
	int &ret = dp[S][E];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = S; i < E; i++)
		ret = min(ret, Sum(S, i) + Sum(i + 1, E) + sum[E] - sum[S - 1]);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << Sum(1, N) << '\n';
	}
	return 0;
}