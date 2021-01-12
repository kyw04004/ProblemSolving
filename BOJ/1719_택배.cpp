//플로이드워셜
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int n, m,input[205][205], ans[205][205];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			input[i][j] = 1e9;
		}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		input[a][b] = c, input[b][a] = c;
		ans[a][b] = b, ans[b][a] = a;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) {
			if (k == i) continue;
			for (int j = 1; j <= n; j++) {
				if (k == j || i == j) continue;
				if (input[i][j] > input[i][k] + input[k][j]) {
					input[i][j] = input[i][k] + input[k][j];
					ans[i][j] = ans[i][k];
				}
			}
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == 0) cout << "- ";
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}