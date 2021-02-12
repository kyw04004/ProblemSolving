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
int n, q, k, arr[100005],dif[100005], ans,sum[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> q >> k;
	arr[0] = 0;
	arr[n + 1] = k + 1;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	if (n >= 3) {
		for (int i = 1; i <= n; i++) {
			dif[i] = arr[i + 1] - arr[i - 1] - 2;
			sum[i] = sum[i - 1] + dif[i];
		}
	}
	for (int i = 0; i < q; i++) {
		int ans = 0;
		int a, b; cin >> a >> b;
		if (n == 1) {
			cout << k - 1 << '\n';
			continue;
		}
		ans = sum[b - 1] - sum[a];
		ans += (k + 1 - arr[b - 1] - 2);
		ans += (arr[a + 1] - arr[0] - 2);
		cout << ans <<'\n';
	}
	return 0;
}