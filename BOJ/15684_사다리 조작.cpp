#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, m, h,ladder[31][11],ans=1e9;
bool possible() {
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][now]) now++;
			else if (ladder[j][now - 1]) now--;
		}
		if (i != now) return false;
	}
	return true;
}
void go(int nowh, int add) {
	if (add >= ans) return;
	if (possible()) {
		ans = min(ans, add);
		return;
	}
	if(add >= 3 || add >= h) return;
	for (int i = nowh; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
			ladder[i][j] = 1;
			go(i, add + 1);
			ladder[i][j] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}
	go(1, 0);
	if (ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}