#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int t, n, m,arr1[20001],arr2[20001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> arr1[i];
		for (int i = 0; i < m; i++) cin >> arr2[i];
		sort(arr1, arr1 + n);
		sort(arr2, arr2 + m);
		for (int i = 0; i < n; i++) {
			int left = 0, right = m - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr2[mid] >= arr1[i]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			cnt += left;
		}
		cout << cnt << '\n';
	}
	return 0;
}