#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int n, chk[100001],cnt, hope[100001],finished[100001];
void dfs(int now) {
	chk[now] = 1;
	int next = hope[now];
	if (!chk[next]) dfs(next);
	else if (!finished[next]) {
		for (int i = next; i != now; i = hope[i])
			cnt++;
		cnt++;
	}
	finished[now] = 1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(chk, 0, sizeof(chk));
		memset(finished, 0, sizeof(finished));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> hope[i];
		for (int i = 1; i <= n; i++)
			if(!chk[i]) dfs(i);
		cout << n - cnt << "\n";
	}
	return 0;
}