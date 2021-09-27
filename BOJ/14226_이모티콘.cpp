#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int S, dp[1005][1005];
int go(int screen, int clipboard) {
	if (screen > 1000) return 1e9;
	if (screen == S) return 0;
	int& ret = dp[screen][clipboard];
	if (ret != -1) return ret;
	ret = 1e9;
	ret = min(ret, go(screen, screen) + 1);
	if(clipboard >= 1) ret = min(ret, go(screen + clipboard, clipboard) + 1);
	if(screen >= 1) ret = min(ret, go(screen - 1, clipboard) + 1);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> S;
	cout << go(1, 0);
	return 0;
}

