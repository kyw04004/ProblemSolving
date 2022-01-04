#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m, sum[10005], ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		sum[i] = sum[i - 1] + val;
	}
	for (int i = 1; i <= n; i++) {
		int left = 0, right = i;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (sum[i] - sum[mid] == m) {
				ans++;
				break;
			}
			else if (sum[i] - sum[mid] < m) right = mid - 1;
			else left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}