#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
int n, l, leftcnt, leftMax, rightMax;
vector<pair<int, int>> ans;
int main() {
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (val < 0) {
			leftMax = max(leftMax, -val);
			leftcnt++;
		}
		else rightMax = max(rightMax, l - val);
		ans.push_back({ abs(val), i });
	}
	sort(ans.begin(), ans.end());
	if (leftMax > rightMax) printf("%d %d\n", ans[leftcnt - 1].second, leftMax);
	else printf("%d %d\n", ans[leftcnt].second, rightMax);
	return 0;
}