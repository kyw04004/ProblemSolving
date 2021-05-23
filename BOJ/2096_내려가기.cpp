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
int N, Max, Min=1e9;
pair<int, int> dp[2][3];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int one, two, three;
	cin >> one >> two >> three;
	dp[0][0].first = dp[0][0].second = one;
	dp[0][1].first = dp[0][1].second = two;
	dp[0][2].first = dp[0][2].second = three;
	for (int j = 2; j <= N; j++) {
		cin >> one >> two >> three;
		dp[1][0].first = max(dp[0][0].first, dp[0][1].first) + one;
		dp[1][0].second = min(dp[0][0].second, dp[0][1].second) + one;

		dp[1][1].first = max(dp[0][0].first, max(dp[0][1].first, dp[0][2].first)) + two;
		dp[1][1].second = min(dp[0][0].second, min(dp[0][1].second, dp[0][2].second)) + two;

		dp[1][2].first = max(dp[0][1].first, dp[0][2].first) + three;
		dp[1][2].second = min(dp[0][1].second, dp[0][2].second) + three;

		dp[0][0].first = dp[1][0].first;
		dp[0][1].first = dp[1][1].first;
		dp[0][2].first = dp[1][2].first;

		dp[0][0].second = dp[1][0].second;
		dp[0][1].second = dp[1][1].second;
		dp[0][2].second = dp[1][2].second;
	}
	for (int i = 0; i < 3; i++)
		Max = max(Max, dp[0][i].first), Min = min(Min, dp[0][i].second);
	cout << Max << ' ' << Min;
	return 0;
}