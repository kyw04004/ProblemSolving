#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
ll n, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll left = 0, right = 4e9;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll num = mid * mid;
		if (num == n) {
			ans = mid;
			break;
		}
		else if (num > n) right = mid - 1, ans = mid;
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}