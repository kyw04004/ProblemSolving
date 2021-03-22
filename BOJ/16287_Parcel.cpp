#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int w, n, arr[5001], dp[400005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> w >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int now = w - arr[i] - arr[j];
			if (0 <= now && now <= 400000) {
				if (dp[now]) {
					cout << "YES\n";
					return 0;
				}
			}
		}
		for (int j = 0; j < i; j++)
			if (arr[i] + arr[j] <= w)
				dp[arr[i] + arr[j]] = 1;
	}
	cout << "NO\n";
	return 0;
}