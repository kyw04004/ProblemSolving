#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, n, arr[100005];
int go(int depth, int ans) {
	if (depth >= n) {
		if (n >= 2 && arr[depth - 1] == arr[depth]) ans++;
		return ans;
	}
	if (arr[depth] == arr[depth + 1]) go(depth + 1, ans);
	else {
		if (arr[depth] == arr[depth - 1]) {
			arr[depth]++;
			if (arr[depth] == arr[depth + 1]) go(depth + 1, ans + 1);
			else go(depth + 1, ans + 2);
		}
		else go(depth + 1, ans + 1);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 1;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		cout << go(1, 1) << '\n';
	}
	return 0;
}