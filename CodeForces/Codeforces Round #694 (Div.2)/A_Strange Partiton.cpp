#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll n, x, arr[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t; cin >> t;
	while (t--) {
		ll Max = 0, Min, sum = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum += arr[i];
			Max += (arr[i] - 1) / x;
			Max += 1;
		}
		Min = (sum - 1) / x;
		Min += 1;
		cout << Min << ' ' << Max << '\n';
	}
	return 0;
}