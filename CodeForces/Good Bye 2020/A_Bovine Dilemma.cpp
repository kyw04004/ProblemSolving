#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, n, m, arr[51];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		int sum[51] = { 0, };
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++)
				sum[arr[j] - arr[i]]++;
		for (int i = 1; i <= 50; i++)
			if (sum[i]) ans++;
		cout << ans << '\n';
	}
	return 0;
}